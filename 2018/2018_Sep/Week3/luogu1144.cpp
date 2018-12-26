#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
const int mod=100003;
const int base=1e9+7;
struct edge{
	int to,next;
}es[MAXN*4];
int tot,head[MAXN];
void init(int N){
	tot=0;
	for(int i=0;i<=N;++i)head[i]=-1;
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int d[MAXN];
void bfs(int u){
	queue<int>q;
	q.push(u);d[u]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(d[v])continue;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
}

int dp[MAXN];
int visit[MAXN];
void solve(){
	dp[1]=1;
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(visit[u])continue;
		visit[u]=1;//DAG保证每个点只访问一次
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(d[v]==d[u]+1){
				dp[v]=(dp[v]+dp[u])%mod;
				q.push(v);
			}
		}
	}
}

inline int read(){
	char ch;
	while(1){
		ch=getchar();
		if(ch>='0'&&ch<='9')break;
	}
	int res=ch-'0';
	while((ch=getchar())>='0' && ch<='9')res=res*10+ch-'0';
	return res;
}

int main(){
	int N,M;scanf("%d%d",&N,&M);
	init(N);
	for(int i=0;i<M;++i){
		int a,b;
		a=read();b=read();
		if(a==b)continue;
		addEdge(a,b);
		addEdge(b,a);
	}
	memset(d,0,sizeof(d));
	bfs(1);
	solve();
	for(int i=1;i<=N;++i)
		printf("%d\n",dp[i]);
	return 0;
}
