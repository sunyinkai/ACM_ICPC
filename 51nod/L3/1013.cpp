#include<bits/stdc++.h>
using namespace std;
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

long long inv(long long a,long long p){
	return  a==1?1:(p-p/a)*inv(p%a,p)%p;
}

int main(){
	long long N;scanf("%lld",&N);
	printf("%lld\n",(fast_pow(3,N+1)-1+mod)%mod*inv(2,mod)%mod);
	return 0;
}
