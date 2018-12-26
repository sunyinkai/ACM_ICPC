#include<cstdio>
#include<cstring>
const int MAXM=2e4+7;
const int MAXN=1007;
const long long INF=1e10+7;

struct edge{
	int from,to,cost;
}es[MAXM];
long long d[MAXN];int N,M;
bool bellman_ford(int s){
	for(int i=1;i<=N;++i)d[i]=INF;
	d[s]=0;
	for(int i=0;i<=N;++i){
		bool update=false;
		for(int j=0;j<M;++j){
			int u=es[j].from,v=es[j].to;
			if(d[v]>d[u]+es[j].cost){
				d[v]=d[u]+es[j].cost;
				update=true;
			}
		}
		if(i==N&&update)return true;
	}
	return false;
}
int main(){
	scanf("%d",&N);
	int ML,MD;scanf("%d%d",&ML,&MD);
	M=ML+MD;
	int tot=0;
	for(int i=0;i<ML;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		es[tot].from=b;es[tot].to=a;es[tot].cost=c;
		tot++;
	}
	for(int i=ML;i<ML+MD;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		es[tot].from=a;es[tot].to=b;es[tot].cost=-c;
		tot++;
	}
	if(bellman_ford(N)){
		printf("-1\n");
	}else{
		/*for(int i=1;i<=N;++i)
			printf("d[%d]=%d\n",i,d[i]);*/
		if(d[1]==INF)printf("-2\n");
		else printf("%lld\n",d[1]);
	}
	return 0;
}
