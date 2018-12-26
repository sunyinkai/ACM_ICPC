#include<cstdio>
#include<cstring>
const int MAXN=1007;
const int mod=10056;
int res[MAXN];
int a[MAXN],b[MAXN];
//C[n][k]:n匹马,k组
//C[i][j]=(C[i-1][j-1]+C[i-1][j])*j;
void init(){
	a[1]=1;
	res[1]=1;
	for(int i=2;i<MAXN;++i){
		b[1]=1;
		res[i]=(res[i]+b[1])%mod;
		for(int j=2;j<=i;++j){
			b[j]=(a[j-1]+a[j])*j%mod;
			res[i]=(res[i]+b[j])%mod;
		}
		for(int k=1;k<=i+1;++k){
			a[k]=b[k];
		}
	}
}
int main(){
	init();
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n;scanf("%d",&n);
		printf("Case %d: %d\n",test,res[n]);
	}
	return 0;
}
