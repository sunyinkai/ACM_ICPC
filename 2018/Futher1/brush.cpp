#include<cstdio>
#include<cstring>
const int MAXE=1007;
const int MAXV=107;
const int INF=1e9+7;
struct edge{ 
	int from,to,cost;
}es[MAXE*2];
int d[MAXV];
int main(){ 
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){ 
		int N,M;scanf("%d%d",&N,&M);
		for(int i=0;i<M;++i){ 
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			es[i].from=a;es[i].to=b;es[i].cost=c;
			es[i+M].from=b;es[i+M].to=a;es[i+M].cost=c;
		}
		for(int i=1;i<=N;++i)d[i]=INF;
		d[1]=0;
		for(int i=0;i<N;++i){ 
			for(int j=0;j<2*M;++j){ 
				edge &e=es[j];
				if(d[e.to]>d[e.from]+e.cost){ 
					d[e.to]=d[e.from]+e.cost;
				}
			}
		}
		printf("Case %d: ",test);
		if(d[N]==INF)printf("Impossible\n");
		else printf("%d\n",d[N]);
	}
	return 0;
}
