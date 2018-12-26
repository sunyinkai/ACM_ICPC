#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
 
typedef long long ll;
using namespace std;
const int maxn = 5000 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
struct Edge
{
    int to, rev;
    ll cap;
    Edge(int to_, ll cap_, int rev_):to(to_),cap(cap_),rev(rev_){}
};
vector<Edge> G[maxn];
int level[maxn];
int iter[maxn], n, m; //用于当前弧优化
ll node_val[maxn];
bool vis[maxn];
 
void add_edge(int from, int to, ll cap)
{
    //printf("build edge from %d to %d: %lld\n", from, to, cap);
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}
 
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++) {
            Edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
 
 
 
ll dfs(int v, int t, ll f)
{
    if(v == t)  return f;
    for(int& i = iter[v]; i < G[v].size(); i++) {
        Edge& e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
 
ll max_flow(int s, int t)
{
    ll flow = 0;
    for(;;) {
        bfs(s);
        if(level[t] < 0)    return flow;
        memset(iter, 0, sizeof(iter));
        ll f;
        while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    //return flow;
}
 
int ans = 0;
void dfs1(int s)
{
    vis[s] = true;
   printf("visit %d\n", s);
    ans++;
    for(int i = 0; i < G[s].size(); i++) {
        Edge e = G[s][i];
        if(e.cap > 0 && !vis[e.to])  dfs1(e.to);
    }
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i <= n; i++) G[i].clear();
 
        int s = 0, t = n + 1;
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> node_val[i];
            if(node_val[i] > 0) {
                sum += node_val[i];
                add_edge(s, i, node_val[i]);
            } else if(node_val[i] < 0) {
                add_edge(i, t, -node_val[i]);
            }
        }
 
        int u, v;   //u->v
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v, INF);
        }
 
        ans = 0;
        ll ans_val = sum - max_flow(s, t);
        memset(vis, 0, sizeof(vis));
        dfs1(s);
        printf("%d %lld\n", ans-1, ans_val);
    }
    return 0;
}
