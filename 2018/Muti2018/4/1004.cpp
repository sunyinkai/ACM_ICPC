#include<cstdio>
#include<cstring>
#include<cmath>
int main(){
	int T;scanf("%d",&T);
	for(int i=0;i<T;++i){
		long long N,M;scanf("%lld%lld",&N,&M);
		long long a,b;
		double ans=0.0;
		for(int i=0;i<N;++i){
			scanf("%lld%lld",&a,&b);
			ans+=M*1.0/(a+b)*a;
		}
		long long x=ans;
		printf("%lld\n",(x+M-1)/M);
	}
	return 0;
}
