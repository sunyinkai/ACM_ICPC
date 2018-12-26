#include<cstdio>
const int MAXN=1e4+7;
int par[MAXN];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i){
		par[i]=i;
	}
	for(int i=0;i<M;++i){
		int q;scanf("%d",&q);
		if(q==1){
			int a,b;scanf("%d%d",&a,&b);
			a=find(a);b=find(b);
			if(a!=b)par[a]=b;
		}else{
			int a,b;scanf("%d%d",&a,&b);
			int x=find(a),y=find(b);
			if(x==y)printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
