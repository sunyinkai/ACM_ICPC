#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int  MAXM =6e5+7;
const  int MAXN =6e5+7;
const long long mod=998244353;
vector<int> G[MAXN];
int low[MAXN], dfn[MAXN];
int dfs_clock;
int sccno[MAXN], scc_cnt;
int N,M;
stack<int> S;
bool Instack[MAXN];
int du[MAXN];

void init(int N){
	//1...N  N+1...N+N
	for(int i=1;i<=N;++i)G[i].clear(),G[i+N].clear();
	for(int i=1;i<=N;++i)sccno[i]=0,sccno[i+N]=0;
	for(int i=1;i<=N;++i)Instack[i]=Instack[i+N]=0;
	for(int i=1;i<=N;++i)du[i]=du[i+N]=0;
	scc_cnt=dfs_clock=0;
	for(int i=1;i<=N;++i)low[i]=dfn[i]=low[i+N]=dfn[i+N]=0;
	while(!S.empty())S.pop();
}

void tarjan(int u, int fa){
	int v;
	low[u] = dfn[u] = ++dfs_clock;
	S.push(u);
	Instack[u] = true;
	int len=G[u].size();
	for(int i = 0; i <len; ++i){
		v = G[u][i];
		if(!dfn[v]){
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if(Instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if(low[u] == dfn[u]){
		scc_cnt++;
		for(;;){
			v = S.top(); S.pop();
			Instack[v] = false;
			sccno[v] = scc_cnt;
			if(v == u) break;
		}
	}
}

int visit[MAXN];
vector<int>base[MAXN];
int hasVisit=0;

int even,odd;
void dfs(int u,int pre){
	if(u<=N&&!visit[u]){
		visit[u]=1;
		++hasVisit;
		if(sccno[u]>sccno[u+N])++odd;
		else ++even;
	}
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		dfs(v,u);
	}
}

int main(){

	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		init(N);
		for(int i=0;i<M;++i){
			int u,v;scanf("%d%d",&u,&v);
			++du[u];++du[v];
			base[u].push_back(v);
			base[v].push_back(u);
			G[u].push_back(v+N);
			G[v+N].push_back(u);
			G[u+N].push_back(v);
			G[v].push_back(u+N);
		}
		for(int i=1;i<=N;++i)
			if(!dfn[i])tarjan(i,-1);

		bool hasAns=true;
		for(int i=1;i<=N;++i){
			if(sccno[i]==sccno[i+N])hasAns=false;
		}

		if(!hasAns){printf("0\n");continue;}
		else{
			hasVisit=0;
			long long ans=1;
			for(int i=1;i<=2*N;++i)visit[i]=0;
			while(hasVisit!=N){
				for(int i=1;i<=N;++i){
					if(du[i]==0)ans=ans*3%mod,++hasVisit,visit[i]=1;

					even=odd=0;
					if(!visit[i])dfs(i,-1);
					long long tmp=0;
					if(odd||even){
							long long t=1;
							t=1;
							for(int i=1;i<=odd;++i)
								t=t*2%mod;
							tmp+=t;
							t=1;
							for(int i=1;i<=even;++i)
								t=t*2%mod;
							tmp+=t;
					}
					printf("tmp:%lld\n",tmp);
					ans=ans*tmp%mod;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
