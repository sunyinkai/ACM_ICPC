#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=107;
const int MAXE=1e4+7;
const int INF=1e9+7;
struct edge{
	int u,v,c;
	bool operator<(const edge&other)const{
		return c<other.c;
	}
}es[MAXE];

int par[MAXV],visit[MAXV];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)&&N+M){
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
		}

		sort(es,es+M);

		int ans=INF;
		for(int i=0;i<M;++i){
			for(int j=1;j<=N;++j)par[j]=j;
			memset(visit,0,sizeof(visit));

			int minE=es[i].c,maxE=0;
			int cnt=0;
			for(int j=i;j<M;++j){
				int u=es[j].u,v=es[j].v;
				u=find(u);v=find(v);
				if(u!=v){
					par[u]=v;
					maxE=es[j].c;
					++cnt;
				//	printf("x=%d,y=%d\n",x,y);
				}
			}
			if(cnt==N-1){
				if(maxE-minE<ans)ans=maxE-minE;
			}
		}
		if(ans==INF)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
