#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXV=1007;
int dfn[MAXV],low[MAXV];
int V,E;
int iscut[MAXV];
int time;
vector<int>G[MAXV];
int dfs(int u,int pre){//low[u]:u以及他的后代,能够达到最小的dfn值
	dfn[u]=low[u]=++time;
	int len=G[u].size();
	int child=0;
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(!dfn[v]){
			++child;
			int lowv=dfs(v,u);
			low[u]=min(low[u],lowv);
			if(lowv>=dfn[u])iscut[u]=1;
		}else if(v!=pre&&dfn[v]<dfn[u]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(pre==-1&&child==1)iscut[u]=0;
	return low[u];
}
int main(){
	scanf("%d%d",&V,&E);
	for(int i=0;i<E;++i){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	time=0;
	dfs(1,-1);
	for(int i=1;i<=V;++i){
		if(iscut[i])printf("%d\n",i);
	}
	return 0;
}
