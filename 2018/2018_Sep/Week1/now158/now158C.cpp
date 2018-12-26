#include<cstdio>
#include<cstring>
const long long mod=1e9+7;
const int MAXN=1e5+7;
long long a[MAXN];
long long fast_pow(long long base,long long n){
	long long res=1;
	while(n){
		if(n&1)res=res*base%mod;
		base=base*base%mod;
		n/=2;
	}
	return res;
}

long long inv(long long t,long long p){
	return t==1?1:(p-p/t)*inv(p%t,p)%p;
}
int main(){
	int N,M;scanf("%d%d",&N,&M);
	long long sum=0;
	for(int i=1;i<=N;++i){
		scanf("%lld",&a[i]);
		sum+=a[i];
		sum%=mod;
	}

	while(M--){
		int x,t;scanf("%d%d",&t,&x);//x次变化,a[t]的值
		long long res=fast_pow(N-1,x)*sum%mod;
		res=(res+ (x%2==1?sum:-sum)+mod)%mod;
		long long tmp=N*a[t]%mod;
		res=(res+mod+(x%2==1?-tmp:tmp))%mod;
		printf("%lld\n",res*inv(N,mod)%mod);
	}
	return 0;
}
