//POJ3264 RMQ
#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

const int MAXN=2e5+7;
int f[MAXN][20],g[MAXN][20];//f:max g:min
void init(int N){
	for(int k=1;k<=20;++k){
		for(int i=1;i+(1<<k)-1<=N;++i){
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
			g[i][k]=min(g[i][k-1],g[i+(1<<(k-1))][k-1]);
		}
	}
}
int query_max(int l,int r){
	int len=r-l+1;
	int k=0;
	while(1<<(k+1)<=len)++k;
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int query_min(int l,int r){
	int len=r-l+1;
	int k=0;
	while(1<<(k+1)<=len)++k;
	return min(g[l][k],g[r-(1<<k)+1][k]);
}

int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i){
		scanf("%d",&f[i][0]);
		g[i][0]=f[i][0];
	}
	init(N);
	while(M--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",query_max(l,r)-query_min(l,r));
	}
	return 0;
}
