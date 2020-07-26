//在最短路的条件下保证最小花费
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+7;
const int MAXM=1e5+7;
const int INF=1e9+7;
struct edge{
    int to,cost,weight;
    bool operator<(const edge&other)const{
        return cost>other.cost;
    }
}es[MAXM];
vector<edge>G[MAXN];
int mindist[MAXN],done[MAXN];
int N,M;
priority_queue<edge>q;
void dijkstra(int s,int t){
    for(int i=1;i<=N;++i)mindist[i]=INF;
    memset(done,0,sizeof(done));
    q.push(edge{s,0,0});
    while(!q.empty()){
        const edge e=q.top();q.pop();
        int u=e.to;
        if(done[u])continue;
        done[u]=1;
        mindist[u]=e.cost;
        int len=G[u].size();
        for(int i=0;i<len;++i){
             q.push(edge{G[u][i].to,G[u][i].cost+mindist[u],0});
        }
    }
}

queue<edge>que;
int mincost[MAXN];
void getMinCost(int s,int t){
    for(int i=1;i<=N;++i)mincost[i]=INF;
    mincost[s]=0;
    que.push(edge{s,0,0});

    while(!que.empty()){
        edge e=que.front();que.pop();
        int u=e.to;
        int len=G[u].size();
        for(int i=0;i<len;++i){
            int v=G[u][i].to;
            if(mindist[v]==mindist[u]+G[u][i].cost){//如果是最短路上的边
                que.push(edge{v,0,mincost[u]+G[u][i].weight});
                mincost[v]=min(mincost[v],mincost[u]+G[u][i].weight);
            }
        }
    }
}

int main(){
    while(~scanf("%d%d",&N,&M)&&N+M){
        for(int i=1;i<=N;++i)G[i].clear();
        for(int i=0;i<M;++i){
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            G[a].push_back(edge{b,c,d});
            G[b].push_back(edge{a,c,d});
        }
        int s,t;scanf("%d%d",&s,&t);
        dijkstra(s,t);
        getMinCost(s,t);
        printf("%d %d\n",mindist[t],mincost[t]);
    }
    return 0;
}
