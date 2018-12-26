#include<cstdio>
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long a,b,x,y;scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
		if(gcd(a,b)==gcd(x,y))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
