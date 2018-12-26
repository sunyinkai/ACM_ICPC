#include<cstdio>
#include<cstring>
const int MAXN=3007;
const int MAXE=3007;
struct edge{
	int u,v,c;
}es[2*MAXE];
int N,M,tot;
int d[MAXN];
bool hasLoop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<N;++i){
		for(int j=0;j<tot;++j){
			if(d[es[j].v]>d[es[j].u]+es[j].c){
				d[es[j].v]=d[es[j].u]+es[j].c;
				if(i==N-1)return true;
			}
		}
	}
	return false;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		tot=M;
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
			if(es[i].c>=0){
				es[tot].u=es[i].v;
				es[tot].v=es[i].u;
				es[tot].c=es[i].c;
				++tot;
			}
		}
		if(hasLoop())printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}
