#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int main(){
	long long n,k;scanf("%lld%lld",&n,&k);
	long long t=k/2;
	long long tt=t;
	if(k%2==0)tt--;
	printf("%lld\n",max(0,min(n-t,tt)));
	return 0;
}
