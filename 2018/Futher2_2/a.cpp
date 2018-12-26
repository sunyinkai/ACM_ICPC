#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
vector<int>G[MAXN];
int dfs_clock,low[MAXN],dfn[MAXN];
int isCut[MAXN];
void dfs(int u,int pre){ 
	low[u]=dfn[u]=++dfs_clock;
	int son=0;
	int len=G[u].size();
	for(int i=0;i<len;++i){ 
		int v=G[u][i];
		if(v==pre)continue;
		if(!dfn[v]){ 
			++son;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){ 
				isCut[u]=1;
			}
		}else low[u]=min(low[u],dfn[v]);
	}
	if(pre==-1&&son==1)isCut[u]=0;
}
struct node{ 
	int id,cnt;
	bool operator<(const node&other)const{ 
		return cnt>other.cnt||(cnt==other.cnt&&id<other.id);
	}
}no[MAXN];

int par[MAXN];
inline int find(int x){ 
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
inline void unit(int x,int y){ 
	x=find(x);
	y=find(y);
	if(x!=y)par[x]=y;
}
int solve(int x,int n){ 
	for(int i=0;i<n;++i)par[i]=i;
	for(int i=0;i<n;++i){ 
		if(i==x)continue;
		int len=G[i].size();
		for(int j=0;j<len;++j){ 
			int v=G[i][j];
			if(v==x)continue;
			unit(i,v);
		}
	}
	int res=0;
	for(int i=0;i<n;++i)par[i]=find(i);
	for(int i=0;i<=n;++i){ 
		if(i==par[i])++res;
	}
	//printf("x=%d,res=%d\n",x,res-1);
	return res-1;
}
int main(){ 
	int N,M;
	int tag=0;
	while(~scanf("%d%d",&N,&M)&&N+M){ 
		tag=1;
		for(int i=0;i<N;++i)G[i].clear();
		for(;1;){ 
			int a,b;scanf("%d%d",&a,&b);
			if(a==-1&&b==-1)break;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		dfs_clock=0;
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(isCut,0,sizeof(isCut));
		dfs(0,-1);

		/*for(int i=0;i<N;++i){ 
			if(isCut[i])printf("%d\n",i);
		}*/

		for(int i=0;i<N;++i){ 
			if(isCut[i]){ 
				no[i].id=i;
				no[i].cnt=solve(i,N);
			}else{ 
				no[i].id=i;
				no[i].cnt=1;
			}
		}

		sort(no,no+N);
		for(int i=0;i<M;++i){ 
			printf("%d %d\n",no[i].id,no[i].cnt);
		}

		printf("\n");
	}
	return 0;
}

