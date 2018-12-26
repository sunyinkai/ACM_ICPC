#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1000+7;
const int  INF=1e9+7;

int ch[MAXN][4];
int isword[MAXN];
int fail[MAXN],last[MAXN];
int mp[MAXN];
int dp[MAXN][MAXN];
int test;
struct AC{
	int tot,root;
	AC(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<4;++i)ch[tot][i]=0;
		isword[tot++]=0;
		return tot-1;
	}
	void insert(const char*s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=mp[s[i]];
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		isword[now]++;
	}
	void build(){
		queue<int>q;
		for(int i=0;i<4;++i){
			int v=ch[0][i];
			if(!v){
				ch[0][i]=0;
			}else{
				last[v]=0;
				fail[v]=0;
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
		char t[MAXN];scanf("%s",t);
		int len=strlen(t);

		printf("Case %d: ",test++);
		for(int i=0;i<=len;++i)
			for(int j=0;j<=tot;++j)dp[i][j]=INF;
		dp[0][0]=0;

		//当前搞到处理到长度i,在AC上位置为j，至少需要的次数
		int now=root;
		for(int i=0;i<len;++i){
			int id=mp[t[i]];
			for(int now=0;now<tot;++now){
				for(int k=0;k<4;++k){
					int v=ch[now][k];
					int tmp=v;
					bool isok=true;
					while(tmp){
						if(isword[tmp]){
							isok=false;
						}
						tmp=fail[tmp];
					}
					
					if(isok){
						int add=1;
						if(k==id)add=0;
						dp[i+1][v]=min(dp[i+1][v],dp[i][now]+add);
					}
				}
			}
		}

		int ans=INF;
		for(int i=0;i<tot;++i)
			ans=min(ans,dp[len][i]);
		printf("%d\n",ans==INF?-1:ans);
	}
};

int main(){
	int N;
	mp['A']=0,mp['G']=1,mp['C']=2,mp['T']=3;
	test=1;
	while(~scanf("%d",&N)&&N){
		AC ac;
		for(int i=0;i<N;++i){
			char s[64];scanf("%s",s);
			ac.insert(s);
		}
		ac.build();
		ac.solve();
	}
	return 0;
}
