#include<cstdio>
#include<cstring>
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
	int T;scanf("%d",&T);
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		if(k<=n){
			long long res=fast_pow(2,n-(k-1));
			printf("%lld\n",(res-(n-(k-1))+mod)%mod);
		}else{
			printf("0\n");
		}
	}
	return 0;
}
