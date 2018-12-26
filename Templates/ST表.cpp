#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
int f[MAXN][21];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)scanf("%d",&f[i][0]);
	for(int k=1;(1<<k)<=N;++k)
		for(int i=1;i+(1<<k)-1<=N;++i)
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
	while(M--){
		int a,b;scanf("%d%d",&a,&b);
		int k=0;
		while(1<<(k+1)<=b-a+1)++k;
		printf("%d\n",max(f[a][k],f[b-(1<<k)+1][k]));
	}
	return 0;
}
