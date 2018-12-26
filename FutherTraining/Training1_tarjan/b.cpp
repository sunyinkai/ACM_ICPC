#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=107;
vector<int>G[MAXN];
int dfn[MAXN],low[MAXN],dfs_clock,cutCnt,iscut[MAXN];
void dfs(int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	int child=0;
	for(auto v:G[u]){
		if(v==pre)continue;
		if(!dfn[v]){
			++child;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				if(!iscut[u]){
					iscut[u]=1;
					++cutCnt;
				}
			}
		}else low[u]=min(low[u],dfn[v]);
	}
	if(pre==-1&&child==1){
		--cutCnt;
		iscut[u]=0;
	}
}
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		for(int i=1;i<=N;++i)G[i].clear();
		while(1){
			int from;scanf("%d",&from);
			if(from==0)break;
			while(1){
				int to;scanf("%d",&to); 
				G[from].push_back(to);
				G[to].push_back(from);
				char ch=getchar();
				if(ch=='\n')break;
			}
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(iscut,0,sizeof(iscut));
		dfs_clock=0;
		cutCnt=0;
		dfs(1,-1);
		printf("%d\n",cutCnt);
	}
	return 0;
}
