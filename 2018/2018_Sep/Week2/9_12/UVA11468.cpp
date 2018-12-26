#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=407;
const int MAXL=107;
int ch[MAXN][62],match[MAXN];
int last[MAXN],fail[MAXN];
int L;
double p[MAXN];
double dp[MAXN][MAXN];//当前处理到第i个字符,处于第j个位置的概率
struct AC{
	int tot,root;
	AC(){
		tot=0;
		root=newnode();
	}
	int idx(char ch){
		int ans;
		if(ch>='a'&&ch<='z')ans=ch-'a';
		if(ch>='A'&&ch<='Z')ans=26+ch-'A';
		if(ch>='0'&&ch<='9')ans=52+ch-'0';
		return ans;
	}

	int newnode(){
		for(int i=0;i<62;++i)ch[tot][i]=0;
		match[tot++]=0;
		return tot-1;
	}
	void insert(const char *s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=idx(s[i]);
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		match[now]=1;
	}
	void build(){
		queue<int>q;
		fail[root]=root;
		for(int i=0;i<62;++i){
			int v=ch[root][i];
			if(!v)ch[root][i]=root;
			else{
				fail[v]=root;
				q.push(v);
				last[v]=0;
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<62;++i){
				int v=ch[u][i];
				if(!v)ch[u][i]=ch[fail[u]][i];
				else{
					fail[v]=ch[fail[u]][i];
					last[v]=match[fail[v]]?fail[v]:last[fail[v]];
	//				match[v]|=match[fail[v]];
					q.push(v);
				}
			}
		}
	}
	void solve(){//T=50
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		for(int k=0;k<L;++k){//100
			for(int now=0;now<tot;++now){//400
				if(!dp[k][now])continue;
				for(int i=0;i<62;++i){//
					if(!p[i])continue;
					int to=ch[now][i];
					if(!last[to])dp[k+1][to]+=dp[k][now]*p[i];
				}
			}
		}

		double ans=0.0;
		for(int i=0;i<=tot;++i)if(!match[i])ans+=dp[L][i];
		printf("%.6f\n",ans);
	}
	
};
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int N;scanf("%d",&N);
		AC ac;
		for(int i=0;i<N;++i){
			char s[27];scanf("%s",s);
			ac.insert(s);
		}
		ac.build();

		int M;scanf("%d",&M);
		memset(p,0,sizeof(p));
		for(int i=0;i<M;++i){
			char s[2];double x;
			scanf("%s%lf",s,&x);
			p[ac.idx(s[0])]=x;
		}
		scanf("%d",&L);
		printf("Case #%d: ",test);
		ac.solve();
	}
	return 0;
}
