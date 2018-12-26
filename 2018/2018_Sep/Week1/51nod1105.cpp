//求两个数组笛卡尔积的第K大 N<=10^5
//O(logN*NlogN)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
long long a[MAXN],b[MAXN];
long long N,K;
bool isok(long long val){
	long long cnt=0;
	for(int i=0;i<N;++i){
		long long x=val/a[i];
		int tot=upper_bound(b,b+N,x)-b;
		cnt+=tot;
	}
	return cnt>=K;
}

int main(){
	scanf("%lld%lld",&N,&K);
	for(int i=0;i<N;++i)scanf("%lld%lld",&a[i],&b[i]);
	long long lo=0,hi=1e18+7;
	sort(a,a+N);
	sort(b,b+N);
	K=N*N-K+1;
	while(hi-lo>1){
		long long mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	printf("%lld\n",hi);
	return 0;
}
