#include <stdio.h>
#define lc 2*o
#define rc 2*o+1
typedef long long ll;
const int maxn = 100010;
const int M = 20;
struct Edge{
	int u, v, nxt;
}e[2 * maxn];
int MOD, a[maxn], head[maxn], e_cnt, ql, qr, qv;
int L[maxn], R[maxn], fa[maxn][M+1], pa[maxn], son[maxn];
int d[maxn], sz[maxn], clk, addv[4 * maxn], sumv[4 * maxn];
void Add(int u, int v){
	int id = e_cnt++;
	e[id].u = u;
	e[id].v = v;
	e[id].nxt = head[u];
	head[u] = id;
}
int DFS_1st(int u, int f){
	d[u] = d[f] + 1;
	fa[u][0] = f;
	for(int i = 1; i < M; i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	sz[u] = 1;
	for(int id = head[u]; id != -1; id = e[id].nxt){
		int v = e[id].v;
		if(v == f) continue;
		sz[u] += DFS_1st(v, u);
		if(son[u] == 0 || sz[v] > sz[son[u]])
			son[u] = v;
	}
	return sz[u];
}
void DFS_2nd(int u, int f, int p){
	L[u] = clk++;
	pa[u] = p;
	if(son[u]) DFS_2nd(son[u], u, son[u]);
	for(int id = head[u]; id != -1; id = e[id].nxt){
		int v = e[id].v;
		if(v == f || v == p) continue;
		DFS_2nd(v, u, v);
	}
	R[u] = clk;
}
int LCA(int u, int v){
	if(d[u] > d[v]){ int t = u; u = v; v = t; }
	int c = d[v] - d[u];
	for(int i = 0; i < M; i++)
		if(c >> i & 1)
			u = fa[u][i],
			v = fa[v][i];
	for(int i = M-1; i >= 0; i--)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i],
			v = fa[v][i];
	return u == v ? u : fa[u][0];
}
void Maintain(int o, int l, int r){
	if(r - l > 1)
		sumv[o] = (sumv[lc] + sumv[rc]) % MOD;
	else
		sumv[o] = 0;
	sumv[o] = (sumv[o] + (ll)addv[o] * (r - l) % MOD) % MOD;
}
void Add_Tree(int o, int l, int r){
	if(ql <= l && r <= qr)
		addv[o] = (addv[o] + qv) % MOD;
	else{
		int mid = (l + r) / 2;
		if(ql < mid) Add_Tree(lc, l, mid);
		if(mid < qr) Add_Tree(rc, mid, r);
	}
	Maintain(o, l, r);
}
int Query_Tree(int o, int l, int r, int add){
	if(ql <= l && r <= qr)
		return (sumv[o] + (ll)(r - l) * add % MOD) % MOD;
	else{
		int mid = (l + r) / 2, rnt = 0;
		if(ql < mid) rnt = (rnt + Query_Tree(lc, l, mid, add+addv[o])) % MOD;
		if(mid < qr) rnt = (rnt + Query_Tree(rc, mid, r, add+addv[o])) % MOD;
		return rnt;
	}
}
void Add_Link(int x, int z, int n){
	for(int u = x; u; u = fa[pa[u]][0]){
		ql = L[pa[u]]; qr = L[u] + 1; qv = z;
		Add_Tree(1, 0, n + 1);
	}
}
int Query_Link(int x, int n){
	int rnt = 0;
	for(int u = x; u; u = fa[pa[u]][0]){
		ql = L[pa[u]]; qr = L[u] + 1;
		rnt = (rnt + Query_Tree(1, 0, n + 1, 0)) % MOD;
	}
	return rnt;
}
int main(){
	int n, m, root;
	scanf("%d%d%d%d", &n, &m, &root, &MOD);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		head[i] = -1;
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		Add(u, v);
		Add(v, u);
	}
	Add(0, root);
	Add(root, 0);
	DFS_1st(0, -1);
	DFS_2nd(root, 0, root);
	for(int i = 1; i <= n; i++){
		ql = L[i]; qr = R[i]; qv = a[i];
		Add_Tree(1, 0, n + 1);
	}
	for(int k = 1; k <= m; k++){
		int ty; scanf("%d", &ty);
		if(ty == 1){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			int r = LCA(x, y);
			Add_Link(x, z, n);
			Add_Link(y, z, n);
			Add_Link(r, -z, n);
			Add_Link(fa[r][0], -z, n);
		}
		else if(ty == 2){
			int x, y;
			scanf("%d%d", &x, &y);
			int r = LCA(x, y);
			int ans = (Query_Link(x, n) + Query_Link(y, n)) % MOD;
			ans = (ans - Query_Link(r, n) + MOD) % MOD;
			ans = (ans - Query_Link(fa[r][0], n) + MOD) % MOD;
			printf("%d\n", ans);
		}
		else if(ty == 3){
			int x, z;
			scanf("%d%d", &x, &z);
			ql = L[x]; qr = R[x]; qv = z;
			Add_Tree(1, 0, n + 1);
		}
		else{
			int x; scanf("%d", &x);
			ql = L[x]; qr = R[x];
			printf("%d\n", Query_Tree(1, 0, n + 1, 0));
		}
	}
	return 0;
}
