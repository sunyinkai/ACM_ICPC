#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1007;
vector<int>G[MAXN];
stack<int>s;
int time=0,low[MAXN],dfn[MAXN];
int sccno[MAXN],scc_cnt;
void dfs(int u){ 
	low[u]=dfn[u]=++time;
	s.push(u);
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
			int x=s.top();s.pop();
			sccno[x]=scc_cnt;
			if(x==u)break;
		}
	}
}

void find_scc(int n){ 
	time=scc_cnt=0;
	memset(sccno,0,sizeof(sccno));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	for(int i=1;i<=n;++i){ 
		if(!dfn[i])dfs(i);
	}
}

int in[MAXN],out[MAXN];
int main(){ 
	int N,M;
	while(~scanf("%d%d",&N,&M)){ 
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=0;i<M;++i){ 
			int a,b;scanf("%d%d",&a,&b);
			G[a].push_back(b);
		}
		find_scc(N);

		if(scc_cnt==1){ 
			printf("0\n");
		}else{ 
			memset(in,0,sizeof(in));
			memset(out,0,sizeof(out));
			for(int u=1;u<=N;++u){ 
				int len=G[u].size();
				for(int i=0;i<len;++i){ 
					int v=G[u][i];
					if(sccno[u]!=sccno[v]){ 
						out[sccno[u]]++;
						in[sccno[v]]++;
					}
				}
			}
			int IN=0,OUT=0;
			for(int i=1;i<=scc_cnt;++i){ 
				if(in[i]==0)++IN;
				if(out[i]==0)++OUT;
			}
			printf("%d\n",max(IN,OUT));
		}
	}
	return 0;
}

