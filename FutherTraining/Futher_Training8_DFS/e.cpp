//二分+2_SAT
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=4007;
int T[MAXN][2];
vector<int>G[MAXN];
int N;
int low[MAXN],dfn[MAXN],dfs_clock=0;
int inStack[MAXN],q[MAXN],top,scc;
int par[MAXN];
void dfs(int u){
	dfn[u]=low[u]=++dfs_clock;
	q[top++]=u;
	inStack[u]=1;
	int len=G[u].size();
	for(int i=0;i<len;++i){
		int v=G[u][i];
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scc++;
		for(;;){
			int no=q[--top];
			inStack[no]=0;
			par[no]=scc;
			if(no==u)break;
		}
	}
}
/*void addEdge(int x,int xval,int y,int yval){
	x=2*x+xval;
	y=2*y+yval;
	G[x^1].push_back(y);
	G[y^1].push_back(x);
}*/
bool isok(int x){
	for(int i=0;i<2*N;++i)G[i].clear();
	for(int i=0;i<N;++i){
		for(int j=0;j<2;++j){
			for(int a=i+1;a<N;++a){
				for(int b=0;b<2;++b){
					if(abs(T[i][j]-T[a][b])<x){
						/*G[i].push_back(a+N);
						G[a].push_back(i+N);没有反应出着路状态*/
						//addEdge(i,j^1,a,b^1);
						if(j==0&&b==0){//1早2早
							G[i].push_back(a+N);
							G[a].push_back(i+N);
						}else if(j==0&&b==1){//1早2晚
							G[i].push_back(a);
							G[a+N].push_back(i+N);
						}else if(j==1&&b==0){//1晚2早
							G[i+N].push_back(a+N);
							G[a].push_back(i);
						}else {//1晚2晚
							G[i+N].push_back(a);
							G[a+N].push_back(i);
						}	
					}
				}
			}
		}
	}
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(inStack,0,sizeof(inStack));
	dfs_clock=top=scc=0;
	for(int i=0;i<2*N;++i)
		if(!dfn[i])dfs(i);
	/*for(int i=0;i<2*N;i+=2)
		if(par[i]==par[i+1])return false;*/
	for(int i=0;i<N;++i)
		if(par[i]==par[i+N])return false;
	return true;

}
int main(){
	while(~scanf("%d",&N)){
		for(int i=0;i<N;++i)
			for(int j=0;j<2;++j)
				scanf("%d",&T[i][j]);
		int lo=0,hi=1e7+1;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		printf("%d\n",lo);
	}
	return 0;
}
