#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN=1e4+7;
struct Edge{ 
	int u,v;
};

int dfn[MAXN],low[MAXN],iscut[MAXN],bccno[MAXN],dfs_clock,bcc_cnt;
vector<int>G[MAXN],bcc[MAXN];
stack<Edge>S;

int cnt[MAXN];
void dfs(int u,int pre){ 
	low[u]=dfn[u]=++dfs_clock;
	int child=0;
	int len=G[u].size();
	for(int i=0;i<len;++i){ 
		int v=G[u][i];
		Edge e=Edge{u,v};
		if(!dfn[v]){ 
			S.push(e);
			child++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){ 
				iscut[u]=1;
				bcc_cnt++;bcc[bcc_cnt].clear();
				for(;;){ 
					Edge x=S.top();S.pop();
					if(bccno[x.u]!=bcc_cnt){ 
						bcc[bcc_cnt].push_back(x.u);
						cnt[x.u]++;
						bccno[x.u]=bcc_cnt;
					}
					if(bccno[x.v]!=bcc_cnt){ 
						bcc[bcc_cnt].push_back(x.v);
						cnt[x.v]++;
						bccno[x.v]=bcc_cnt;
					}
					if(x.u==u&&x.v==v)break;
				}
			
			}	
		}else if(dfn[v]<dfn[u]&&v!=pre){ 
				S.push(e);
				low[u]=min(low[u],dfn[v]);
		}
	}
	if(pre==-1&&child==1)iscut[u]=0;
}

void find_bcc(int n){ 
	memset(dfn,0,sizeof(dfn));
	memset(iscut,0,sizeof(iscut));
	memset(bccno,0,sizeof(bccno));
	memset(cnt,0,sizeof(cnt));//被多少个bcc包含
	dfs_clock=bcc_cnt=0;
	for(int i=0;i<n;++i){ 
		if(!dfn[i])dfs(i,-1);
	}
}

struct node{ 
	int id,cnt;
	bool operator < (const node&other) const{ 
		return cnt>other.cnt||(cnt==other.cnt&&id<other.id);
	}
}no[MAXN];


int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)&&N+M){ 
		for(int i=0;i<=N;++i)G[i].clear();
		for(;;){ 
			int x,y;scanf("%d%d",&x,&y);
			if(x+y==-2)break;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		find_bcc(N);
		for(int i=0;i<N;++i){ 
			no[i].id=i;
			no[i].cnt=cnt[i];
		}
		sort(no,no+N);
		/*printf("bcc_cnt=%d\n",bcc_cnt);
		for(int i=1;i<=bcc_cnt;++i){ 
			int len=bcc[i].size();
			printf("size:%d ",len);
			for(int j=0;j<len;++j){ 
				printf("%d ",bcc[i][j]);
			}
			printf("\n");
		}*/
		for(int i=0;i<M;++i){ 
			printf("%d %d\n",no[i].id,no[i].cnt);
		}
		printf("\n");
	}
	return 0;
}
