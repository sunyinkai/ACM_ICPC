#include<cstdio>
#include<cstring>
const int MAXN=107;
int uN,vN;
int g[MAXN][MAXN],linker[MAXN],used[MAXN];
int dfs(int u){
	for(int v=1;v<=vN;++v){
		if(g[u][v]&&!used[v]){
			used[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int u=1;u<=uN;++u){
		memset(used,false,sizeof(used));
		if(dfs(u))++res;
	}
	return res;
}
int main(){
	while(~scanf("%d%d",&vN,&uN)){
		memset(g,0,sizeof(g));
		for(int i=1;i<=uN;++i){
			int x;scanf("%d",&x);
			for(int j=0;j<x;++j){
				int to;scanf("%d",&to);
				g[i][to]=1;
			}
		}
		printf("%d\n",hungary());
	}
	return 0;
}
