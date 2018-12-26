#include<cstdio>
#include<cstring>
const long long mod=1e9+7;
int main(){
	long long N,P;
	scanf("%lld%lld",&N,&P);
	long long res=1;
	for(int i=1;i<=N;++i){
		res=res*(P-i)%mod;
	}
	printf("%lld\n",res);
	return 0;
}

