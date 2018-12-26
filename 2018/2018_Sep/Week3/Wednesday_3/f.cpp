#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=5e5+7;
int ch[MAXN][26];
int isword[MAXN];
int fail[MAXN],last[MAXN];
char t[MAXN*2];
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
		isword[now]++;
	}
	void build(){
		queue<int>q;
		for(int i=0;i<26;++i){
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
		int now=root;
		int ans=0;
		scanf("%s",t);
		int len=strlen(t);
		for(int i=0;i<len;++i){
			int x=t[i]-'a';
			now=ch[now][x];
			int tmp=now;
			while(tmp){
				if(isword[tmp]){
					ans+=isword[tmp];
					isword[tmp]=0;
				}
				tmp=fail[tmp];
			}
		}
		printf("%d\n",ans);
	}
};

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
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
