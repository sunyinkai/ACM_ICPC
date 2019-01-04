#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long t=__gcd(a+3*b,4*a+4*b);
		printf("%lld/%lld\n",(a+3*b)/t,(4*a+4*b)/t);
	}
	return 0;
}
