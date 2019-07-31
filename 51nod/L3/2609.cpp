//tag: MST
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e4+7;
const int INF=1e9+7;
struct edge{
	int u,v,cost;
	bool operator<(const edge&other)const{
		return cost<other.cost;
	}
}e[MAXN];

int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}

int N,M;
int solve(int id){
	int ans=INF;
	int s_x=-1;
	int tot=0;
	for(int i=id;i<M;++i){
		if(s_x==-1)s_x=e[i].cost;
		int u=e[i].u,v=e[i].v;
		u=find(u);v=find(v);
		if(u!=v){
			par[u]=v;
			++tot;
		}
		if(tot==N-1){
			ans=min(e[i].cost-s_x,ans);
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int i=0;i<M;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].cost);
	}
	sort(e,e+M);
	int ans=INF;
	for(int i=0;i<M;++i){
		for(int i=1;i<=N;++i)par[i]=i;//init
		ans=min(ans,solve(i));
	}
	printf("%d\n",ans);
	return 0;
}
