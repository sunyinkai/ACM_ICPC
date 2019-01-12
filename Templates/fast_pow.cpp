#include<cstdio>
const long long mod=1e9+7;
long long fast_pow(long long base,long long n){
	long long ans=1;
	while(n){
		if(n&1)ans=ans*base%mod;
		base=base*base%mod;
		n/=2;
	}
	return ans;
}
int main(){
	long long a,b;scanf("%lld%lld",&a,&b);
	printf("%lld\n",fast_pow(a,b));
	return 0;
}
