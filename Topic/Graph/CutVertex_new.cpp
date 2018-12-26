#include<cstdio>
#include<cstring>
int dfn[MAXV],time=0;
bool isCut[MAXV];
int dfs(int u,int pre){
	dfn[u]=low[u]=++time;
	int child=0;
	for(auto i:G[u]){
		int v=G[u][i];
		if(v==pre)continue;
		if(!dfn[v]){
			++child;
			low[u]=min(low[u],dfs(v,u));
			if(low[v]>=dfn[u]){
				isCut[u]=true;
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(pre==-1&&child==1)isCut[u]=0;
	return low[u];
}
int main(){

	return 0;
}
