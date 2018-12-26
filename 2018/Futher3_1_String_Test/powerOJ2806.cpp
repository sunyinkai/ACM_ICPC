#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
//2018.9.17

const int MAXN=1e5+7;
const long long mod=1e9+7;
char s[MAXN],t[MAXN];
int N,M;
int ch[MAXN][26],isword[MAXN];
int fail[MAXN],last[MAXN];
long long dp[MAXN];

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
	void insert(const char*s){
		int len=strlen(s);
		int now=root;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			if(!ch[now][x])ch[now][x]=newnode();
			now=ch[now][x];
		}
		isword[now]=len;
	}
	void build(){
		queue<int>q;
		int now=root;
		for(int i=0;i<26;++i){
			int v=ch[now][i];
			if(!v)ch[now][i]=0;
			else{
				fail[v]=0;
				last[v]=0;
				q.push(v);
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;++i){
				int v=ch[u][i];
				if(!v){
					ch[u][i]=ch[fail[u]][i];
				}else{
					fail[v]=ch[fail[u]][i];
					last[v]=isword[fail[v]]?fail[v]:last[fail[v]];
					q.push(v);
				}
			}
		}
	}
	void solve(){
		dp[0]=1;	
		int now=root;//当前所在位置
		for(int i=0;i<N;++i){
			int x=s[i]-'a';
			dp[i+1]=0;
			now=ch[now][x];
			int tmp=now;
			while(tmp){
				if(isword[tmp]){
					int len=isword[tmp];
					dp[i+1]=(dp[i+1]+dp[i+1-len])%mod;
				}
				tmp=last[tmp];
			}
		}
		for(int i=1;i<=N;++i)
			printf(i==1?"%lld":" %lld",dp[i]);
		printf("\n");
	}
};

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		scanf("%s",s);
		AC ac;
		while(M--){
			scanf("%s",t);
			ac.insert(t);
		}
		ac.build();
		ac.solve();
	}
	return 0;
}
