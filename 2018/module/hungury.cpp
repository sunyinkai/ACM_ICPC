#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=107;
int linker[MAXN],visit[MAXN];
vector<int>G[MAXN];
bool dfs(int u){
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(visit[v])continue;
		visit[v]=1;
		if(linker[v]==-1||dfs(linker[v])){
			linker[v]=u;
			return true;
		}
	}
	return false;
}

int main(){
	int N,M;
	while(scanf("%d%d",&N,&M)){
		for(int i=0;i<N;++i)G[i].clear();
		for(int i=0;i<M;++i){
			int x;scanf("%d",&x);
			while(x--){
				int to;scanf("%d",&to);
				G[i].push_back(to);
			}
		}
		int res=0;
		memset(linker,-1,sizeof(linker));
		for(int i=0;i<N;++i){
			memset(visit,0,sizeof(visit));
			if(dfs(i))++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
