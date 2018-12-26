#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#define min(a,b) (a<b?a:b)
using namespace std;
const int MAXV=1007;
int dfn[MAXV],low[MAXV];
int time=0;
bool instack[MAXV];
stack<int>s;
vector<int>G[MAXV];
int scc;//强连通数量
int belong[MAXV];//缩点
void dfs(int u,int pre){//u及其后代能够达到的最早dfn值
	dfn[u]=low[u]=++time;
	int len=G[u].size();
	s.push(u);
	instack[u]=true;
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[v],low[u]);
		}else if(instack[u]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		scc++;
		for(;;){
			int x=s.top();s.pop();
			belong[x]=scc;
			instack[x]=false;
			if(x==u)break;
		}
	}
}
void init(){
	scc=0;
	time=0;
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(instack,0,sizeof(instack));
}
int main(){
	init();
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i){
		int x,y;scanf("%d%d",&x,&y);
		G[x].push_back(y);
	}
	for(int i=1;i<=N;++i){
		if(!dfn[i])dfs(i,-1);
	}
	printf("scc=%d\n",scc);
	return 0;
}
