#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
int par[MAXN],cnt[MAXN];
long long sum[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
struct edge{
	int u,v,c;
	bool operator<(const edge&other)const{
		return c>other.c;
	}
}es[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=0;i<N-1;++i){
			scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
		}
		sort(es,es+N-1);
		for(int i=1;i<=N;++i)par[i]=i,cnt[i]=1,sum[i]=0;
		for(int i=0;i<N-1;++i){
			int u=es[i].u,v=es[i].v;
			u=find(u);v=find(v);
			long long sumu=sum[u]+(long long)es[i].c*cnt[v];
			long long sumv=sum[v]+(long long)es[i].c*cnt[u];
			if(sumu<sumv){
				sum[v]=sumv;
				cnt[v]+=cnt[u];
				par[u]=v;
			}else{
				sum[u]=sumu;
				par[v]=u;
				cnt[u]+=cnt[v];
			}
		}
		printf("%lld\n",sum[find(1)]);
	}
	return 0;
}
