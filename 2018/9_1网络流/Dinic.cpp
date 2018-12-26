#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int INF=1e9+7;
const int MAXN=407;
struct Edge{
    int from,to,cap,flow;
};
int s,t;
vector<Edge>edges;
vector<int>G[MAXN];

void addEdge(int from,int to,int cap){
    edges.push_back((Edge){from,to,cap,0});
    edges.push_back((Edge){to,from,0,0});
    int m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

bool visit[MAXN];
int d[MAXN];
int cur[MAXN];

bool BFS(){//1,根据残留网络构造层次图
    memset(visit,0,sizeof(visit));
    queue<int>Q;
    Q.push(s);
    d[s]=0;
    visit[s]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        for(int i=0;i<G[x].size();++i){
            Edge &e=edges[G[x][i]];
            if(!visit[e.to]&&e.cap>e.flow){//没有被访问过且还有剩余
                visit[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return visit[t];//3,已经不能达到汇点退出
}
int DFS(int x,int a){//从s->x的最小剩余流量,2,在层次图中进行增广
    if(x==t||a==0)return a;
    int flow=0,f;
    for(int &i=cur[x];i<G[x].size();++i){
        Edge &e=edges[G[x][i]];
        if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int Maxflow(int s,int t){
    int flow=0;
    while(BFS()){
        memset(cur,0,sizeof(cur));
        flow+=DFS(s,INF);
    }
    return flow;
}
int main(){
    
    return 0;
}