#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+7;
long long A[MAXN],B[MAXN];
long long N,K;
bool isok(long long x){
	long long ans=0;
	for(int i=1;i<=N;++i){
		long long val=x/A[i];
		ans+=upper_bound(B+1,B+N+1,val)-B-1;
	}
	return ans>=K;
}

int main(){
	scanf("%lld%lld",&N,&K);
	for(int i=1;i<=N;++i)
		scanf("%lld%lld",&A[i],&B[i]);
	sort(B+1,B+N+1);
	K=N*N-K+1;
	long long lo=0,hi=1e18+8;
	while(hi-lo>1){
		long long mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	printf("%lld\n",hi);
	return 0;
}
