#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=4e5+7;
const long long mod=1e9+7;
int ch[MAXN][26],isword[MAXN];
int fail[MAXN],last[MAXN];
long long dp[MAXN];
char s[MAXN];
struct AC{
	int tot,root;
	AC(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<26;++i)ch[tot][i]=0;
		last[tot]=0;
		isword[tot++]=0;
		return tot-1;
	}
	void insert(const char *s){
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
		fail[root]=root;
		for(int i=0;i<26;++i)
			if(!ch[root][i])ch[root][i]=root;
			else {
				fail[ch[root][i]]=root;
				q.push(ch[root][i]);
				last[ch[root][i]]=0;
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
		int len=strlen(s);
		dp[0]=1;
		int now=root;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			now=ch[now][x];
			dp[i+1]=0;
			int temp=now;
			while(temp){
				if(isword[temp]){
					int len=isword[temp];
					dp[i+1]=(dp[i+1]+dp[i+1-len])%mod;
				}
				temp=last[temp];
			}
		}
		for(int i=1;i<=len;++i)
			printf(i==1?"%lld":" %lld",dp[i]);
		printf("\n");
	}
};

char t[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,M;scanf("%d%d",&N,&M);
		AC ac;
		scanf("%s",s);
		for(int i=0;i<M;++i){
			scanf("%s",t);
			ac.insert(t);
		}
		ac.build();
		ac.solve();
	}
	return 0;
}
