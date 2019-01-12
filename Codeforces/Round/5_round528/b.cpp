#include<cstdio>
#define min(a,b) (a<b?a:b)
const long long INF=1e15+7;
long long ans=INF;
long long n,k;

void solve(long long a,long long b){
	long long begin=a*k;
	long long end=(a+1)*k;
	for(long long i=begin;i<end;++i){
		if(i==0)continue;
		if(i%k==b){
			ans=min(ans,i);
		}
	}
}

int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i*i<=n;++i){
		if(n%i==0){
			long long a=i;
			long long b=n/i;
			solve(a,b);
			solve(b,a);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
