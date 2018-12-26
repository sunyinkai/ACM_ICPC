//A(n,m) * m^(n-m) (X)
//n,m<=1e6,mod=1e9+7;
#include<cstdio>
const long long mod=1e9+7;
//C(a,b)
long long inv(long long a,long long p){
	return a==1?1:(p-p/a)*inv(p%a,p)%p;
}

long long C(long long a,long long b){//复杂度O(n)
	long long res=1;
	for(long long i=1;i<=b;++i){
		res=res*(a-i+1)%mod*inv(i,mod)%mod;
	}
	return res;
}

int main(){
	long long N,M;scanf("%lld%lld",&N,&M);
	if(N<M){
		printf("0\n");
		return 0;
	}

	long long ans=1;
	for(long long i=N;i>=N-M+1;--i)
		ans=ans*i%mod;
	for(long long i=0;i<N-M;++i)
		ans=ans*M%mod;
	//ans=ans*C(N,M)%mod;
	printf("%lld\n",ans);
	return 0;
}
