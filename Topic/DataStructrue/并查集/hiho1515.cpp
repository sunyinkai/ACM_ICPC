#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int d[MAXN],par[MAXN];
int find(int x){ 
	if(par[x]==x)return par[x];
	int t=par[x];
	par[x]=find(par[x]);
	d[x]+=d[t];
	return par[x];
}
int main(){ 
	int N,M,Q;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int i=0;i<M;++i){ 
		int x,y,s;scanf("%d%d%d",&x,&y,&s);
		//x比y高s
		int fx=find(x);
		int fy=find(y);
		if(fx==fy)continue;
		par[fx]=fy;
		d[fx]=d[y]+s-d[x];
	}
	for(int i=0;i<Q;++i){ 
		int x,y;
		scanf("%d%d",&x,&y);
		int m=x,n=y;
		x=find(x);
		y=find(y);
		if(x!=y){ 
			printf("-1\n");
		}else{ 
			printf("%d\n",d[m]-d[n]);
		}
	}
	return 0;
}
