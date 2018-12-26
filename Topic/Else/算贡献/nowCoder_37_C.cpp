#include<cstdio>
const long long mod=1e9+7;
long long fast_pow(long long base,long long n){
	long long res=1;
	while(n){
		if(n&1)res=res*base%mod;
		base=base*base%mod;
		n/=2;
	}
	return res;
}
int main(){
	long long n;
	while(~scanf("%lld",&n)){
		if(n<=1){
			printf("0\n");
		}else{
			long long N=n;
			n%=mod;
			printf("%lld\n",n*(n-1)/2%mod*fast_pow(2,N-2)%mod);
		}
	}
	return 0;
}
