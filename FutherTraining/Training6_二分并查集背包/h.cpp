#include<cstdio>
#include<cmath>
long long fast_pow(long long base,long long n){
	long long res=1;
	while(n){
		if(n&1)res=res*base;
		base*=base;
		n/=2;
	}
	return res;
}
int main(){
	long long n;
	while(~scanf("%lld",&n)&&n){
		long long res=0;
		long long tmp=sqrt(n);
		if(tmp*tmp==n){//平方的情况
			res+=(tmp-1)/2;
		}
		for(long long z=3;z<=32;++z){//z
			long long limit=1;
			while(fast_pow(limit,z)<=2e9)++limit;
			for(long long x=1;;++x){//x
				long long tmp=fast_pow(x,z);
				if(tmp>n)break;
				long long remain=n-tmp;
				long long lo=0,hi=limit;
				while(hi-lo>1){//二分y
					long long mid=(hi+lo)/2;
					if(fast_pow(mid,z)+mid*x*z>=remain)hi=mid;
					else lo=mid;
				}
				if(hi<x)break;
				if(fast_pow(hi,z)+hi*z*x==remain&&x<hi)++res;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
