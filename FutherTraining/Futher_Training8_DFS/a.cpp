#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1007;
struct edge{
	int u,v;
};
int N,M;
int dfs_clock,low[MAXN],dfn[MAXN];
stack<edge>S;
vector<int>G[MAXN];
vector<edge>bcc[MAXN];
int bccno[MAXN],bcc_cnt;
void dfs(int ,int );
void find_bcc(){
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(bccno,0,sizeof(bccno));
	for(int i=0;i<=N;++i)bcc[i].clear();
	while(!S.empty())S.pop();
	bcc_cnt=dfs_clock=0;
	for(int i=1;i<=N;++i)if(!dfn[i])dfs(i,-1);
}
void dfs(int u,int pre){
	low[u]=dfn[u]=++dfs_clock;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(v==pre)continue;
		edge e=(edge){u,v};
		if(!dfn[v]){
			S.push(e);
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				bcc_cnt++;
				for(;;){
					edge x=S.top();S.pop();
					bcc[bcc_cnt].push_back(x);
					if(x.u==u&&x.v==v)break;
				}
			}
		}
		else if(dfn[v]<dfn[u]){
				S.push(e);
				low[u]=min(low[u],dfn[v]);
		}
	}
}

int mp[MAXN][MAXN];
void read(){
	memset(mp,0,sizeof(mp));
	for(int i=0;i<M;++i){
		int a,b;scanf("%d%d",&a,&b);
		mp[a][b]=mp[b][a]=1;
	}
	for(int i=1;i<=N;++i)G[i].clear();
	for(int i=1;i<=N;++i){
		for(int j=i+1;j<=N;++j){
			if(!mp[i][j]){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}

}
struct edges{
	int next,to;
}es[2*MAXN*MAXN];
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int visit[MAXN],col[MAXN],tag;
bool isBinary(int u,int x){
	col[u]=x;
	//printf("col[%d]=%d\n",u,col[u]);
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
	//	printf("v=%d,col[v]=%d\n",v,col[v]);
		if(col[v]){
			if(col[v]+col[u]!=0)tag=0;
		}else{
			isBinary(v,-x);
		}
	}
}
void solve(){
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=bcc_cnt;++i){
		init();
		for(int j=0;j<bcc[i].size();++j){
			edge e=bcc[i][j];
			addEdge(e.u,e.v);
		//	printf("%d->%d\n",e.u,e.v);
			addEdge(e.v,e.u);
		}
		//printf("\n");
		memset(col,0,sizeof(col));
		tag=1;
		isBinary(bcc[i][0].u,-1);
	//	printf("begin=%d,tag=%d\n\n",bcc[i][0].u,tag);
		if(!tag){
			for(int j=0;j<bcc[i].size();++j){
				edge e=bcc[i][j];
				visit[e.u]=visit[e.v]=1;
	//			printf("e.u=%d,e.v=%d\n",e.u,e.v);
			}
		}
	}
	int ans=N;
	for(int i=1;i<=N;++i)if(visit[i])--ans;
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d%d",&N,&M)&&N+M){
		read();
		find_bcc();
		solve();
	}
	return 0;
}
