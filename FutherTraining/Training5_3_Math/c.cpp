#include<cstdio>
int main(){
	long long n;scanf("%lld",&n);
	long long res=0;
	res=n*(n-1)*(n-2)*(n-3)*(n-4)/120*n*(n-1)*(n-2)*(n-3)*(n-4);
	printf("%lld\n",res);
	return 0;
}
