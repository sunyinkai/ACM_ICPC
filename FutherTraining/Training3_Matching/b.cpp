#include<cstdio>
#include<cstring>
const int MAXN=207;
int g[MAXN][MAXN],used[MAXN],linker[MAXN],col[MAXN];
bool isBinary;
int N,M;
void judge(int u,int pre,int k){
	col[u]=k;
	for(int i=1;i<=N;++i){
		if(!g[u][i])continue;
		int v=i;
		if(v==pre)continue;
		if(v){
			if(!col[v])judge(v,u,-k);
			else if(col[v]==-k);
			else if(col[v]==k){
				isBinary=false;
				return ;
			}
		}
	}
}
int line[MAXN][MAXN];
bool dfs(int u){
	for(int v=1;v<=N;++v){
		if(line[u][v]&&!used[v]){
			used[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
int match(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1;i<=N;++i){
		memset(used,false,sizeof(used));
		if(dfs(i))++res;
	}
	return res;
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		memset(g,0,sizeof(g));
		for(int i=0;i<M;++i){
			int x,y;scanf("%d%d",&x,&y);
			g[x][y]=g[y][x]=1;
		}
		memset(col,0,sizeof(col));
		memset(line,0,sizeof(line));
		isBinary=true;
		for(int i=1;i<=N;++i){
			if(!col[i])judge(i,-1,-1);
		}
		if(!isBinary){
			printf("No\n");
		}else{
			for(int i=1;i<=N;++i){
				for(int j=1;j<=N;++j){
					if(g[i][j]&&col[i]==1&&col[j]==-1){
						line[i][j]=1;
					}
				}
			}
			printf("%d\n",match());
		}
	}
	return 0;
}
