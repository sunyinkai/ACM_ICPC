#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1e4+7;
int low[MAXN],dfn[MAXN],sccno[MAXN];
int size[MAXN];
int time,scc_cnt;
stack<int>S;
vector<int>G[MAXN];
void dfs(int u){ 
	low[u]=dfn[u]=++time;
	S.push(u);
	int len=G[u].size();
	for(int i=0;i<len;++i){ 
		int v=G[u][i];
		if(!dfn[v]){ 
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(!sccno[v]){ 
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){ 
		scc_cnt++;
		for(;;){ 
			int x=S.top();S.pop();
			sccno[x]=scc_cnt;//代表元
	//		printf("%d->%d\n",x,scc_cnt);
			size[scc_cnt]++;
			if(x==u)break;
		}
	}
}

void find_scc(int n){
	time=scc_cnt=0;
	memset(sccno,0,sizeof(sccno));
	memset(dfn,0,sizeof(dfn));
	memset(size,0,sizeof(size));
	memset(low,0,sizeof(low));
	while(!S.empty())S.pop();
	for(int i=1;i<=n;++i){ 
		if(!dfn[i])dfs(i);
	}
}

int in[MAXN],out[MAXN],visit[MAXN];
int main(){ 
	int N,M;
	while(~scanf("%d%d",&N,&M)){ 
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=0;i<M;++i){ 
			int x,y;scanf("%d%d",&x,&y);
			G[x].push_back(y);
		}

		find_scc(N);
	//	printf("scc_cnt=%d\n",scc_cnt);
		if(scc_cnt==1){ 
			printf("%d\n",N);
		}else{ 
			memset(in,0,sizeof(in));	
			memset(out,0,sizeof(out));
			memset(visit,0,sizeof(visit));
			for(int u=1;u<=N;++u){ 
				int len=G[u].size();
				for(int j=0;j<len;++j){
					int v=G[u][j];//u->v
	//				printf("%d->%d\n",sccno[u],sccno[v]);
					if(sccno[u]!=sccno[v]){ 
						out[sccno[u]]++;
						in[sccno[v]]++;
					}
				}
			}
			int u=1;
			int cnt=0,now;
			for(;u<=scc_cnt;++u){ 
				if(out[u]==0)++cnt,now=u;
			}
			if(cnt>=2)printf("0\n");
			else printf("%d\n",size[now]);
		}

	}
	return 0;	 
}
