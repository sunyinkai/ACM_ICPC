#include<cstdio>
#include<cstring>
const int MAXN=107;
long long A[MAXN][MAXN],B[MAXN][MAXN],C[MAXN][MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=a;++i)
			for(int j=1;j<=b;++j)
				scanf("%lld",&A[i][j]);
		for(int i=1;i<=c;++i)
			for(int j=1;j<=d;++j)
				scanf("%lld",&B[i][j]);

		printf("Case %d:\n",test);
		if(b!=c){
			printf("ERROR\n");
		}else{
			for(int i=1;i<=a;++i)
				for(int j=1;j<=d;++j){
					C[i][j]=0;
					for(int k=1;k<=b;++k){
						C[i][j]+=A[i][k]*B[k][j];
					}
				}
			for(int i=1;i<=a;++i){
				for(int j=1;j<=d;++j){
					printf(j==1?"%lld":" %lld",C[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
