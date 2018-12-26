#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN=1e6+7;
int ch[MAXN][26];
int fail[MAXN],last[MAXN];
int isword[MAXN];
struct AC{
	int root,tot;
	AC(){
		tot=0;
		root=newnode();
	}
	int newnode(){
		for(int i=0;i<26;++i)
			ch[tot][i]=0;
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
		isword[now]++;
	}

	void build(){
		queue<int>q;
		fail[root]=root;
		for(int i=0;i<26;++i){
			int v=ch[root][i];
			if(!v)ch[root][i]=i;
			else{
				fail[v]=root;
				last[v]=0;
				q.push(v);
			}
		}

		while(!q.empty()){
			int now=q.front();q.pop();
			for(int i=0;i<26;++i){
				int v=ch[now][i];
				if(!v)ch[now][i]=ch[fail[now]][i];
				else{
					fail[v]=ch[fail[now]][i];
					last[v]=isword[fail[v]]?fail[v]:last[fail[v]];
					q.push(v);
				}
			}
		}
	}

	void solve(const char*s){
		int len=strlen(s);
		int now=root;
		int ans=0;
		for(int i=0;i<len;++i){
			int x=s[i]-'a';
			now=ch[now][x];
			int tmp=now;
			while(tmp!=root){
				if(isword[tmp]){
					ans+=isword[tmp];
					isword[tmp]=0;
				}
				tmp=last[tmp];
			}
		}
		printf("%d\n",ans);
	}
};

char t[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		AC ac;
		for(int i=0;i<N;++i){
			char s[60];scanf("%s",s);
			ac.insert(s);
		}
		ac.build();
		scanf("%s",t);
		ac.solve(t);
	}
}
