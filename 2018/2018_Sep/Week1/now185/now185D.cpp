#include<cstdio>
//只有完全平方数的因子个数为奇数
int main(){
	long long n;
	scanf("%lld",&n);
	long long lo=0,hi=1e9+7;
	while(hi-lo>1){
		long long mid=(hi+lo)/2;
		if(mid*mid>n)hi=mid;
		else lo=mid;
	}
	printf("%lld\n",lo);
	return 0;
}
