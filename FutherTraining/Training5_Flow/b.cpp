#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
//多源多汇节点有限制最小费用最大流
const int MAXN=307;
const int INF=1e9+7;
char s[MAXN][MAXN];
int hashMan[MAXN*MAXN];
int hashHou[MAXN*MAXN];
set<int>Hou,Man;
int N,M,ID;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge>es;
vector<int>G[MAXN];
void addEdge(int a,int b,int cap,int cost){
	es.push_back((edge){a,b,cap,0,cost});
	es.push_back((edge){b,a,0,0,-cost});
	int m=es.size();
	G[a].push_back(m-2);
	G[b].push_back(m-1);
}

int beginNode,endNode;
int abs(int x){
	if(x>0)return x;
	else return -x;
}
void init(){
	for(int i=0;i<M;++i)scanf("%s",s[i]);
	int people=0;
	ID=1;
	Hou.clear();Man.clear();
	memset(hashMan,0,sizeof(hashMan));
	memset(hashHou,0,sizeof(hashHou));
	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j){
			if(s[i][j]=='m'){
				++people;
				hashMan[i*N+j]=ID++;
				Man.insert(i*N+j);
			}else if(s[i][j]=='H'){
				hashHou[i*N+j]=ID++;
				Hou.insert(i*N+j);
			}
	}
	//init
	for(int i=0;i<=3*people+1;++i)G[i].clear();
	es.clear();

	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			if(s[i][j]=='m'){
				int from=hashMan[i*N+j];
				for(set<int>::iterator it=Hou.begin();it!=Hou.end();it++){
					int to=hashHou[*it];
					int xx=*it/N,yy=*it%N;
					int cost=abs(i-xx)+abs(j-yy);
					addEdge(from,to,1,cost);
				}
				addEdge(0,from,1,0);
			}
	int cnt=1;
	for(set<int>::iterator it=Hou.begin();it!=Hou.end();it++){
		int to=hashHou[*it];
		addEdge(to,2*people+cnt,1,0);
		addEdge(2*people+cnt,3*people+1,1,0);
		++cnt;
	}
	beginNode=0,endNode=3*people+1;
}

int inq[MAXN],d[MAXN],p[MAXN],a[MAXN];
bool bellman(int s,int t,int &flow,int &cost){
	//printf("s=%d,t=%d\n",s,t);
	for(int i=0;i<=endNode;++i)d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();++i){
			edge &e=es[G[u][i]];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				p[e.to]=G[u][i];
				a[e.to]=min(a[u],e.cap-e.flow);
				if(!inq[e.to])Q.push(e.to),inq[e.to]=1;
			}
		}
	}
	if(d[t]==INF)return false;
	flow+=a[t];
	cost+=d[t]*a[t];
	int u=t;
	while(u!=s){
		es[p[u]].flow+=a[t];
		es[p[u]^1].flow-=a[t];
		u=es[p[u]].from;
	}
	return true;
}
int Mincost(int s,int t){
	int flow=0,cost=0;
	while(bellman(s,t,flow,cost));
	//printf("flow=%d,cost=%d\n",flow,cost);
	return cost;
}
int main(){
	while(~scanf("%d%d",&M,&N)&&N+M){
		init();
		printf("%d\n",Mincost(beginNode,endNode));
	}
	return 0;
}
