#include<cstdio>
const long long mod=10;
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
	long long a;scanf("%lld",&a);
	printf("%lld\n",fast_pow(a%10,a));
	return 0;
}
