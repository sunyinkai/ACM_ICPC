const int MAXN=510;
int uN,vN;
int g[MAXN][MAXN];//u->v;
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
	for(int v=0;v<vN;++v){
		if(g[u][v]&&!used[v]){//还没有被找过
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u; return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<uN;++u){
		memset(used,false,sizeof(used));
		if(dfs(u))++res;
	}
	return res;
}
