#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=107;
const int MAXLEN=27;
const int mod=20090717;
int ch[MAXN][26],isword[MAXN];
int fail[MAXN],last[MAXN];
int N,M,K;

int dp[MAXLEN][MAXN][1<<10];//11*107*1024
//长度为i,终止节点为now,包含串S的数量
struct AC{
	int tot,root;
	AC(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<26;++i)ch[tot][i]=0;
		isword[tot++]=0;
		return tot-1;
	}

	void insert(const char*s,int cnt){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		isword[now]=(1<<cnt);
	}

	void build(){
		queue<int>q;
		int now=root;
		for(int i=0;i<26;++i){
			int v=ch[now][i];
			if(!v)ch[now][i]=0;
			else{
				last[v]=0;fail[v]=0;
				q.push(v);
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;++i){
				int v=ch[u][i];
				if(!v)ch[u][i]=ch[fail[u]][i];
				else{
					fail[v]=ch[fail[u]][i];
					last[v]=isword[fail[v]]?fail[v]:last[fail[v]];
					q.push(v);
				}
			}
		}
	}

	void solve(){
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(int i=0;i<N;++i){//单词长度 25
			for(int now=0;now<tot;++now){//当前所在位置 100
				for(int S=0;S<(1<<M);++S){//当前集合状态
					if(!dp[i][now][S])continue;

					for(int x=0;x<26;++x){//转移
						int v=ch[now][x];
						int temp=v;
						int nS=S;
						while(temp){//添加一个字符会引入多少新的单词
							if(isword[temp]){
								nS|=isword[temp];
							}
							temp=last[temp];
						}
						dp[i+1][v][nS]=(dp[i+1][v][nS]+dp[i][now][S])%mod;
					}
				}
			}
		}

		int res=0;
		for(int now=0;now<tot;++now){
			for(int S=0;S<(1<<M);++S){
				int cnt=__builtin_popcount(S);
				if(cnt>=K)res=(res+dp[N][now][S])%mod;
			}
		}
		printf("%d\n",res);
	}
};
int main(){
	while(scanf("%d%d%d",&N,&M,&K)&&N+M+K){
		AC ac;
		for(int i=0;i<M;++i){
			char s[15];scanf("%s",s);
			ac.insert(s,i);
		}
		ac.build();
		ac.solve();
	}
	return 0;
}
