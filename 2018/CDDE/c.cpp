//矩阵快速幂　pow(a,n) 不能对n取模
#include<cstdio>
#include<cstring>
long long mod=1e9+7;
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
	return a==1?1:(p-p/a)*inv(p%a,p)%p;
}
int main(){
	long long A,B,n,x; scanf("%lld%lld%lld%lld",&A,&B,&n,&x);
	if(A==1){
		n%=mod;
		printf("%lld\n",(n*B%mod+x)%mod);
	}else{
		long long t=inv(A-1,mod);
		long long res=(fast_pow(A,n)-1+mod)*t%mod*B%mod;
		res=(res+fast_pow(A,n)*x)%mod;
		printf("%lld\n",res%mod);
	}
	return 0;
}
