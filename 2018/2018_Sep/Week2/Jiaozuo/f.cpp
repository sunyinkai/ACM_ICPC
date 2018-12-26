#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 420;
struct Edge{
    int from, to, cap, flow, cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};
struct MCMF{
    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int inq[MAXN],d[MAXN],p[MAXN],a[MAXN];

    void init(int n){
        this->n = n;
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,long long cost){
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BellmanFord(int s,int t,int &flow,long long &cost){
        for(int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof inq);
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

        queue<int>  Q;
        Q.push(s);
        while(!Q.empty()){
            int u = Q.front(); Q.pop();
            inq[u] = 0;
			int len=G[u].size();
            for(int i = 0; i < len; i++){
                Edge& e = edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to] = d[u]+e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u],e.cap-e.flow);
                    if(!inq[e.to]) {Q.push(e.to); inq[e.to] = 1;}
                }
            }
        }
        if(d[t]==INF) return false;
        flow += a[t];
        cost += (long long)d[t]*(long long)a[t];
        for(int u = t; u!=s; u = edges[p[u]].from){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        return true;
    }
    int MincostMaxflow(int s,int t,long long &cost){
        int flow = 0;
        cost = 0;
        while(BellmanFord(s,t,flow,cost));
        return flow;
    }
};
int u[MAXN], v[MAXN], w[MAXN];
vector<int>G;
map<int,int> mp;
int main(){
    int T, n, k;
	scanf("%d",&T);
    while(T--){
        int s = 0, t;
		int len;scanf("%d",&len);
        scanf("%d%d",&k,&n);
        G.clear();
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
			u[i]--;
		//	printf("l=%d,r=%d\n",u[i],v[i]);
            G.push_back(u[i]);
            G.push_back(v[i]);
        }
        sort(G.begin(),G.end());
        G.erase(unique(G.begin(),G.end()),G.end());
        mp.clear();
		int len2=G.size();
        for(int i = 0; i < len2; i++){
            mp[G[i]] = i+1;
        }
        t = G.size()+1;
        MCMF mcmf;
        mcmf.init(t);
        mcmf.AddEdge(s,1,k,0);
        mcmf.AddEdge(G.size(),t,k,0);
		int xlen =G.size();
        for(int i = 1; i < xlen; i++){
            mcmf.AddEdge(i,i+1,INF,0);
        }
        for(int i = 1; i <= n; i++){
            mcmf.AddEdge(mp[u[i]],mp[v[i]],1,-w[i]);
        }
        LL cost;
        int flow = mcmf.MincostMaxflow(s,t,cost);
        printf("%lld\n",-cost);
    }
    return 0;
}
