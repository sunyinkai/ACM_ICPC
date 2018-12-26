#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, a, b) for (i = (a); i <= (b); i ++)

using namespace std;

struct Edge {
	int ed, nxt;
};

const int maxn = 2e5 + 10, maxm = 1e6 + 10;
int n, m, indx, bcnt, maxno;
bool isBridge[maxm << 1], vis[maxn];
int cnt[2], DFN[maxn], low[maxn], belong[maxn], depth[maxn];
int hed[2][maxn];
Edge e[2][maxm << 1];

inline void addEdge(int o, int u, int v) {
	e[o][cnt[o]].ed = v;
	e[o][cnt[o]].nxt = hed[o][u];
	hed[o][u] = cnt[o] ++;
}
	inline void setMin(int &a, int b) {
	if (a > b) {
		a = b;
	}
}

void Tarjan(int u, int fe) {
	int i, j, k, v;
	DFN[u] = low[u] = ++ indx;
	for (i = hed[0][u]; i != -1; i = e[0][i].nxt) {
		v = e[0][i].ed;
		printf("i=%d,i^1=%d,fe=%d,u=%d,v=%d\n",i,i^1,fe,u,v);
		if ((i ^ 1) == fe) {
			continue;
		}
		printf("Tag\n");
		if (!DFN[v]) {
			Tarjan(v, i);
			setMin(low[u], low[v]);
			if (low[v] > DFN[u]) {
				isBridge[i] = isBridge[i ^ 1] = 1;
			}
		}
		else {
			setMin(low[u], DFN[v]);
		}
	}
}

void DFS1(int u, int fa) {
	int i, j, k, v;
	vis[u] = 1;
	belong[u] = bcnt;
	for (i = hed[0][u]; i != -1; i = e[0][i].nxt) {
		v = e[0][i].ed;
		if (vis[v] || isBridge[i] || v == fa) {
			continue;
		}
		DFS1(v, u);
	}
}

void DFS2(int u, int fa) {
	int i, j, k, v;
	for (i = hed[1][u]; i != -1; i = e[1][i].nxt) {
		v = e[1][i].ed;
		if (v == fa) {
			continue;
		}
		depth[v] = depth[u] + 1;
		if (depth[maxno] < depth[v]) {
			maxno = v;
		}
		DFS2(v, u);
	}
}

int main() {
	int i, j, k, u, v;
	for (; scanf("%d%d", &n, &m) && n; ) {
		memset(cnt, 0, sizeof(cnt));
		memset(hed, -1, sizeof(hed));
		rep(i, 1, m) {
			scanf("%d%d", &u, &v);
			addEdge(0, u, v);
			addEdge(0, v, u);
		}
		indx = 0;
		Tarjan(1, -1);
		bcnt = 0;
		rep(i, 1, n) {
			if (!belong[i]) {
				bcnt ++;
				DFS1(i, 0);
			}
		}
		rep(i, 0, cnt[0] - 1) {
			if (isBridge[i]) {
				addEdge(1, u = belong[e[0][i].ed], v = belong[e[0][i ^ 1].ed]);
				addEdge(1, v, u);
				i ++;
			}
		}
		maxno = 1;
		depth[1] = 0;
		DFS2(1, 0);
		depth[maxno] = 0;
		DFS2(maxno, 0);
		printf("%d\n", bcnt - 1 - depth[maxno]);
		memset(DFN, 0, sizeof(DFN));
		memset(isBridge, 0, sizeof(isBridge));
		memset(vis, 0, sizeof(vis));
		memset(belong, 0, sizeof(belong));
	}
	return 0;
}

