#include<cstdio>
#include<cstring>
#include<vector>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int MAXV=107;
vector<int>G[MAXV];
int dfn[MAXV],low[MAXV];
int iscut[MAXV];
int time;
int dfs(int u,int pre){
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
		}
		else if(dfn[v]<dfn[u]&&v!=pre){ low[u]=min(low[u],dfn[v]); }
	}
	if(pre==-1&&child==1){
		iscut[u]=0;
	}
	return low[u];
}
int main(){
	int V,E;
	while(~scanf("%d",&V)&&V){
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(iscut,0,sizeof(iscut));
		time=0;
		for(int i=1;i<=V;++i)G[i].clear();
		while(1){
			int x;scanf("%d",&x);
			if(x==0)break;
			while(1){
				char ch=getchar();
				if(ch=='\n')break;
				int y;scanf("%d",&y);
				G[x].push_back(y);
				G[y].push_back(x);
			}
		}
		dfs(1,-1);
		int res=0;
		for(int i=1;i<=V;++i){
			if(iscut[i]){
				++res;
			}
		}
		printf("%d\n",res);
	}

	return 0;
}
