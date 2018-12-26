#include<cstdio>
long long gcd(long long a,long long b){ 
	return b?gcd(b,a%b):a;
}
int main(){ 
	long long n,m;
	while(~scanf("%lld%lld",&n,&m)&&n+m){ 
		long long fenzi=(m-1)*n;
		long long fenmu=m*m;
		long long val=gcd(fenzi,fenmu);
		if(m==1)printf("0/%lld\n",fenmu);
		else printf("%lld/%lld\n",fenzi/val,fenmu/val);
	}
	return 0;
}
