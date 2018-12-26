#include <stdio.h>
#include <algorithm>
#include <queue> 
using namespace std;
typedef pair<int, int> Pair;
const int maxn = 1000100;
const int inf = 0x3f3f3f3f;
struct Edge{
	int u, v, c, nxt;
}e[4 * maxn];
int head[2][maxn], e_cnt, d[2][maxn], done[maxn];
priority_queue<Pair> q;
void Add(int t, int u, int v, int c){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].c = c;
	e[id].nxt = head[t][u];
	head[t][u] = id; 
}
void Dij(int *d, int *head, int s, int n){
	for(int i = 1; i <= n; i++){
		d[i] = i == s ? 0 : inf;
		done[i] = false;
	}
	q.push(Pair(0, s));
	while(!q.empty()){
		int u = q.top().second; q.pop();
		if(done[u]) continue;
		done[u] = true;
		for(int id = head[u]; id != -1; id = e[id].nxt){
			int v = e[id].v;
			if(d[u] + e[id].c < d[v]){
				d[v] = d[u] + e[id].c;
				q.push(Pair(-d[v], v));
			}
		}
	}
}
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			head[0][i] = head[1][i] = -1;
		e_cnt = 0;
		for(int i = 0; i < m; i++){
			int u, v, t;
			scanf("%d%d%d", &u, &v, &t);
			if(t == 0){
				Add(0, u, v, 1);
				Add(0, v, u, 1);
				Add(1, u, v, 2); 
				Add(1, v, u, 2);
			}
			else if(t == 1){
				Add(0, u, v, 0);
				Add(0, v, u, 0);
				Add(1, u, v, 1); 
				Add(1, v, u, 1);
			}
			else{
				Add(1, u, v, 0); 
				Add(1, v, u, 0);
			}
		}
		Dij(d[0], head[0], 1, n);
		Dij(d[1], head[1], n, n);
		int ans = inf;
		for(int i = 1; i <= n; i++)
		 	ans = min(ans, d[0][i] + d[1][i]);
		printf("%d\n", ans);
	}
	return 0;
}
