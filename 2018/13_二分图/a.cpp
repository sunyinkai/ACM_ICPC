#include<cstdio>
#include<cstring>
const int MAXN=107;
int used[MAXN],linker[MAXN],g[MAXN][MAXN];
int uN,vN;
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
int hungury(){
	int res=0;
	for(int i=1;i<=uN;++i){
		memset(used,0,sizeof(used));
		if(dfs(i))++res;
	}
	return res;
}

int x[MAXN],y[MAXN];
int main(){
	int N,M,K;
	int test=1;
	while(~scanf("%d%d%d",&N,&M,&K)){
		uN=N,vN=M;
		memset(g,0,sizeof(g));
		for(int i=0;i<K;++i){
			int x,y;scanf("%d%d",&x,&y);
			g[x][y]=1;
		}
		memset(linker,-1,sizeof(linker));
		int res=hungury();
		int ans=0;
		int top=0;
		for(int v=1;v<=vN;++v){
			if(linker[v]!=-1){
				x[top]=linker[v];
				y[top++]=v;
			}
		}

		int tmp[MAXN];
		for(int i=0;i<MAXN;++i)tmp[i]=linker[i];
		for(int i=0;i<top;++i){
			for(int i=0;i<MAXN;++i)linker[i]=tmp[i];
			//x[i]->y[i]
			linker[y[i]]=-1;
			g[x[i]][y[i]]=0;
			int t=hungury();
			printf("u:%d v:%d res:%d\n",x[i],y[i],t);
			if(t!=res)++ans;
			g[x[i]][y[i]]=1;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",test,ans,res);
		++test;
	}
	return 0;
}
