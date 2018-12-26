#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=107;

char s[MAXN][MAXN];
int linker[MAXN];
int visit[MAXN],g[MAXN][MAXN];
int ans[MAXN][MAXN];
int N;
bool dfs(int u){
	for(int v=0;v<N;++v){
		if(g[u][v]&&!visit[v]){
			visit[v]=1;
			if(linker[v]==-1||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}

int col[MAXN],row[MAXN];

int main(){
	int S;scanf("%d",&S);
	while(S--){
		scanf("%d",&N);
		memset(g,0,sizeof(g));
		for(int i=0;i<N;++i)scanf("%s",s[i]);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(s[i][j]=='.')ans[i][j]=0;
				else{
					row[i]++;col[j]++;
				}
				g[i][j]=1;
			}
		}
		int top=0;
		for(int i=0;i<N;++i)top=max(max(top,row[i]),col[i]);
		printf("%d\n",top);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				printf(j==N-1?"%d":"%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
