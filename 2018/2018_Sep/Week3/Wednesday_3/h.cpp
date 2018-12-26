#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=1000+7;
const int  MAXLEN=107;
const int INF=1e8;

int ch[MAXN][4],isword[MAXN];
int mp[512];
int last[MAXN],fail[MAXN];
int N,len,cost[11];
int dp[MAXN][1<<10];
struct AC{
	int tot,root;
	AC(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<4;++i)ch[tot][i]=0;
		last[tot]=0;
		isword[tot++]=0;
		return tot-1;
	}
	void insert(const char*s,int val){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=mp[(int)s[i]];
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		isword[now]=val;
	}
	void build(){
		queue<int>q;
		for(int i=0;i<4;++i){
			int v=ch[0][i];
			if(!v)ch[0][i]=0;
			else{
				fail[v]=0;last[v]=0;
				q.push(v);
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<4;++i){
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
			for(int j=0;j<=tot;++j)
				for(int k=0;k<(1<<N);++k)dp[j][k]=-INF;

		dp[0][0]=0;
		for(int i=0;i<len;++i){
			printf("i=%d\n\n\n",i);
			for(int now=0;now<tot;++now){//在Trie上位置
				for(int s=0;s<(1<<N);++s){//已有的集合.
					if(dp[now][s]<0)continue;
					for(int j=0;j<4;++j){
						int to=ch[now][j];
						int tmp=to;
						int nS=s;
						while(tmp){
							if(isword[tmp]){
								nS|=isword[tmp];
							}
							tmp=last[tmp];
						}

						int add=0;
						for(int i=0;i<N;++i)
							if(nS&(1<<i))add+=cost[i];
						printf("i=%d:dp[%d][%d]:%d\n",i,now,s,dp[now][s]);
						dp[to][nS]=max(dp[to][nS],add);
						printf("i+1=%d:dp[%d][%d]:%d\n",i+1,to,nS,dp[to][nS]);
						printf("-------\n");
					}
				}
			}
		}
		int res=-1;
		for(int i=0;i<tot;++i){
			for(int s=0;s<(1<<N);++s){
				res=max(res,dp[i][s]);
			}
		}

		if(res<0)printf("No Rabbit after 2012!\n");
		else printf("%d\n",res);
	}
};

int main(){
	mp[(int)'A']=0;mp[(int)'G']=1;mp[(int)'C']=2;mp[(int)'T']=3;
	while(~scanf("%d%d",&N,&len)){
		AC ac;
		for(int i=0;i<N;++i){
			char s[128];
			scanf("%s%d",s,&cost[i]);
			ac.insert(s,1<<i);
		}

		ac.build();
		ac.solve();
	}
	return 0;
}
