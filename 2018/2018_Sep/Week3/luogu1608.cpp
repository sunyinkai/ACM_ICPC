#include<bits/stdc++.h>
using namespace std;
//考虑重边

typedef pair<int,int>P;
const int MAXN=2007;
const int INF=1e9+7;
const int base=1e9+7;
vector<P>G[MAXN];
int d[MAXN],N,M;
int done[MAXN];
long long dp[MAXN];
void dijkstra(){
	for(int i=1;i<=N;++i)d[i]=INF;
	d[1]=0;dp[1]=1;
	memset(done,0,sizeof(done));
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,1));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
		done[u]=1;

		d[u]=p.first;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].second;
			if(d[v]>d[u]+G[u][i].first){
				dp[v]=dp[u];//将val传下来
				d[v]=d[u]+G[u][i].first;
				q.push(P(d[v],v));
			}else if(d[v]==d[u]+G[u][i].first){
				dp[v]+=dp[u];
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
	while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
	return res;
}
int dis[MAXN][MAXN];

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)G[i].clear();
	for(int i=0;i<M;++i){
		int a,b,c;
		a=read();b=read();c=read();
		if(!dis[a][b]||dis[a][b]>c)dis[a][b]=c;
	}
	for(int i=1;i<=N;++i){
		for(int j=1+i;j<=N;++j){
			if(dis[i][j]){
				G[i].push_back(P(dis[i][j],j));
				G[j].push_back(P(dis[i][j],i));
			}
		}
	}
	dijkstra();
	if(d[N]==INF)printf("No answer\n");
	else{
		printf("%d %lld\n",d[N],dp[N]);
	}
	return 0;
}
