//枚举割边在残留图上增广
//important:割边集合:跑完最大流后vis[e.from]=1&&vis[e.to]=0&&e.cap>0

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=2e9+11;
const int MAXN=107;
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
bool bfs(){//构造层次图
	memset(visit,0,sizeof(visit));
	queue<int>q;
	q.push(s);
	d[s]=0;
	visit[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<G[x].size();++i){
			edge &e=es[G[x][i]];
			if(!visit[e.to]&&e.cap>e.flow){//没有被访问过且流量还有剩余
				visit[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return visit[t];//终点是否被参观过
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
			a-=f;//当前弧优化
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

int N,E,C;
vector<int>Gtmp[MAXN];
vector<edge>estmp;
void copy(){
	estmp.clear();
	for(int i=0;i<=N;++i)Gtmp[i].clear();
	int len=es.size();
	for(int i=0;i<len;++i)estmp.push_back(es[i]);
	for(int i=0;i<=N;++i){
		for(int j=0;j<G[i].size();++j){
			Gtmp[i].push_back(G[i][j]);
		}
	}
}
int top;
struct node{
	int u,v;
	bool operator<(const node&other)const{
		return u<other.u||(u==other.u&&v<other.v);
	}
}no[MAXN*MAXN];
bool solve(int k){
	int has=k;//hasget
	copy();
	int len=estmp.size();
	top=0;
	bool hasAns=false;
	for(int k=0;k<len;k+=2){//枚举加边
		if(estmp[k].cap==estmp[k].flow){
			for(int i=0;i<=N;++i)G[i].clear();
			es.clear();
			for(int i=0;i<len;++i){
				if(i!=k)
					es.push_back(estmp[i]);//边的信息
				else{
					es.push_back({estmp[i].from,estmp[i].to,INF,estmp[i].flow});
				}
	//			printf("%d->%d c=%d f=%d\n",es[i].from,es[i].to,es[i].cap,es[i].flow);
			}

			for(int i=0;i<=N;++i){//图的连接信息
				for(int j=0;j<Gtmp[i].size();++j){
					G[i].push_back(Gtmp[i][j]);
				}
			}
	//		printf("u=%d,v=%d\n",u,v);
			int val=Maxflow(s,t);
			if(has+val>=C){
				//printf("hasval=%d\n",val);
				no[top].u=estmp[k].from;no[top++].v=estmp[k].to;
				hasAns=true;
			}
		}
	}
	return hasAns;
}
int main(){
	int test=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d%d",&N,&E,&C)&&N+E+C){
		es.clear();
		for(int i=0;i<MAXN;++i)G[i].clear();
		for(int i=0;i<E;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
		}
		s=1,t=N;
		int val=Maxflow(s,t);
		printf("Case %d: ",test);
		++test;
		if(val>=C){
			printf("possible\n");
		}else if(solve(val)){
			sort(no,no+top);
			printf("possible option:");
			for(int i=0;i<top;++i){
				if(i!=0)printf(",");
				printf("(%d,%d)",no[i].u,no[i].v);
			}
			printf("\n");
		}else{
			printf("not possible\n");
		}
	}
	return 0;
}
