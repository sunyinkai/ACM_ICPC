#include<cstdio>
#include<cstring>
const int MAXE=2780;
const int MAXV=507;
const long long INF=1e12+7;
struct edge{
	long long from,to,cost;
}e[MAXE];
struct edges{
	long long from,to,cost;
}es[MAXE];
int V,E;
long long d[MAXV];
bool isok(long long val){
	memset(d,0,sizeof(d));
	for(int i=0;i<E;++i){
		es[i].from=e[i].from,es[i].to=e[i].to,es[i].cost=e[i].cost-val;
	//	printf("%d->%d es[i].cost=%d\n",es[i].from,es[i].to,es[i].cost);
	}
	for(int i=0;i<=V;++i){
		bool update=false;
		for(int j=0;j<E;++j){
			int u=es[j].from,v=es[j].to;
			if(d[v]>d[u]+es[j].cost)d[v]=d[u]+es[j].cost,update=true;
		}
		if(i==V&&update)return false;
	}
	return true;

};

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&V,&E)){
		for(int i=0;i<E;++i)
			scanf("%lld%lld%lld",&e[i].from,&e[i].to,&e[i].cost);
		long long lo=0,hi=INF+1;
		if(!isok(1)){
			printf("No Solution\n");
			continue;
		}
		while(hi-lo>1){
			long long mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		if(lo!=INF)
			printf("%lld\n",lo);
		else  
			printf("Infinite\n");
	}
	return 0;
}

