#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int MAXN=22337;
struct edge{ int from,to,cap,flow; };
vector<int>G[MAXN];
vector<edge>es;
void addEdge(int a,int b,int c){
	es.push_back(edge{a,b,c,0});
	es.push_back(edge{b,a,0,0});
	int m=es.size();
	G[a].push_back(m-2);//以a为顶点的第i条边的编号
	G[b].push_back(m-1);
}
bool visit[MAXN];
int d[MAXN];
int cur[MAXN];
int s,t;
bool bfs(){
	memset(visit,0,sizeof(visit));
	queue<int>q;
	q.push(s);
	d[s]=0;
	visit[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<G[x].size();++i){
			edge &e=es[G[x][i]];
			if(!visit[e.to]&&e.cap>e.flow){
				visit[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];
}
int dfs(int x,int a){//从s->x的最小剩余流量
	if(x==t||a==0)return a;
	int flow=0,f;
	for(int &i=cur[x];i<G[x].size();++i){
		edge& e=es[G[x][i]];
		if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
			e.flow+=f;
			es[G[x][i]^1].flow-=f;
			flow+=f;
			a-=f;//?
			if(a==0)break;
		}
	}
	return flow;
}
int Maxflow(int s,int t){
	int flow=0;
	while(bfs()){//每次完成后最短增广路长度单调递
		memset(cur,0,sizeof(cur));
		flow+=dfs(s,INF);
	}
	return flow;
}

struct node{
	int x,y;
}a[MAXN];
int N,M;
int cnt[MAXN];
bool isok(int mid){
	es.clear();
	for(int i=0;i<=M+N+1;++i)G[i].clear();
	for(int i=1;i<=M;++i){
			int x=a[i].x,y=a[i].y;
			addEdge(i,M+x,1);//job->CPU
			addEdge(i,M+y,1);
			addEdge(0,i,1);//s->job
	}
	for(int i=M+1;i<=M+N;++i)
		addEdge(i,N+M+1,mid);//cpu->t
	bool flag=(Maxflow(0,N+M+1)==M);
	return flag;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);//N->CPU,M->job
		memset(cnt,0,sizeof(cnt));
		int lo=0,hi=0;
		for(int i=1;i<=M;++i){
			int x,y;scanf("%d%d",&x,&y);
			cnt[x]++;cnt[y]++;
			a[i].x=x;a[i].y=y;
		}
		for(int i=1;i<=N;++i)
			if(cnt[i]>hi)hi=cnt[i];
		s=0,t=N+M+1;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}
