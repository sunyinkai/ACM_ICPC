//枚举子集+最小生成树
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1007;
const int INF=1e9+7;
vector<int>G[10];
int x[MAXN],y[MAXN];
struct edge{
	int u,v,c;
	bool operator <(const edge&other)const{
		return c<other.c;
	}
}es[MAXN*MAXN];
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		par[x]=y;
	}
}
int main(){
	int T;scanf("%d",&T);
	int tag=0;
	while(T--){
		if(tag)printf("\n");
		tag=1;
		int N,M;scanf("%d%d",&N,&M);
		for(int i=0;i<10;++i)G[i].clear();
		for(int i=0;i<M;++i){
			int x;scanf("%d",&x);
			int val;scanf("%d",&val);
			G[i].push_back(val);
			for(int j=0;j<x;++j){
				scanf("%d",&val);
				G[i].push_back(val);
			}
		}
		for(int i=1;i<=N;++i)scanf("%d%d",&x[i],&y[i]);
		int tot=0;
		for(int i=1;i<=N;++i){
			for(int j=i+1;j<=N;++j){
				es[tot].u=i;
				es[tot].v=j;
				es[tot].c=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				++tot;
			}
		}
		sort(es,es+tot);
		int ans=INF;
		for(int u=0;u<(1<<M);++u){//枚举子集
			int res=0;
			for(int i=1;i<=N;++i)par[i]=i;
			for(int i=0;i<M;++i){
				if((1<<i)&u){
					res+=G[i][0];
					int len=G[i].size();
					for(int x=2;x<len;++x){
						unit(G[i][x],G[i][x-1]);
					}
				 }
			}
			for(int i=0;i<tot;++i){
				int u=es[i].u,v=es[i].v;
				u=find(u);v=find(v);
				if(u!=v){
					unit(u,v);
					res+=es[i].c;
				}
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
