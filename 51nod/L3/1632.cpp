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
	int N;scanf("%d",&N);
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
	}
	printf("%lld\n",fast_pow(2,N-2)*(N+1)%mod);
	return 0;
}
