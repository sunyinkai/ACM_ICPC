#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=107;
int uN,vN;
int N,K;
int g[MAXN][MAXN],linker[MAXN],used[MAXN];
vector<int>G[57];
int dfs(int u){
	for(int v=0;v<vN;++v){
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
bool hungury(){
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<uN;++u){
		memset(used,false,sizeof(used));
		if(dfs(u)){
			++res;
			if(res>K)return false;
		}
	}
	return res<=K;
}

int main(){
	while(scanf("%d%d",&N,&K)&&N+K){
		uN=vN=N;
		for(int i=0;i<57;++i)G[i].clear();
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				int x;scanf("%d",&x);
				G[x].push_back(i*N+j);
			}
		}
		int q[MAXN],top=0;
		for(int col=0;col<=50;++col){
			int len=G[col].size();
			if(len==0)continue;
			memset(g,0,sizeof(g));
			for(int i=0;i<len;++i){
				int t=G[col][i];
				int x=t/N,y=t%N;
				g[x][y]=1;
			}
			if(!hungury())q[top++]=col;
		}
		if(top==0)printf("-1\n");
		else{
			for(int i=0;i<top;++i){
				printf(i==0?"%d":" %d",q[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
