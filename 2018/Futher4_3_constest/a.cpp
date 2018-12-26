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
long long inv(long long a,long long m){ 
	return a==1?1:inv(m%a,m)*(m-m/a)%m;
}
int main(){ 
	long long t,n;
	int T;scanf("%d",&T);
	while(T--){ 
		scanf("%lld%lld",&t,&n) ;
		if(t==1){ 
			printf("%lld\n",n+1);
		}else if(t==0){ 
			printf("1\n");
		}else
			printf("%lld\n",(fast_pow(n,t+1)-1)*inv(n-1,mod)%mod);
	}
	return 0;
}
