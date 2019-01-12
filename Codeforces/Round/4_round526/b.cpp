#include<cstdio>
const int MAXN=1007;
long long a[MAXN];
long long N,S;
bool isok(long long x){
	for(int i=1;i<=N;++i){
		if(a[i]<x)return false;
	}
	long long sum=0;
	for(int i=1;i<=N;++i){
		sum+=a[i]-x;
	}
	return sum>=S;
}
int main(){
	scanf("%lld%lld",&N,&S);
	long long sum=0;
	for(int i=1;i<=N;++i){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(S>sum){
		printf("-1\n");
	}else{
		long long lo=-1,hi=1e9+7;
		while(hi-lo>1){
			long long mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		printf("%lld\n",lo);
	}
	return 0;
}
