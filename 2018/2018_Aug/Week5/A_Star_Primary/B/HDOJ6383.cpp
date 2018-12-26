#include<cstdio>
#include<cstring>
const int MAXN=3e5+7;
int a[MAXN],N;
bool isok(long long x){
	long long sum1=0,sum2=0;
	for(int i=1;i<=N;++i){
		if(a[i]<x)sum1+=x-a[i];
		if(a[i]>x)sum2+=(a[i]-x)/2;
	}
	if(sum1>sum2)return false;
	else return true;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			scanf("%d",&a[i]);
		}
		if(!isok(0)){
			printf("-1\n");
			continue;
		}
		long long lo=0,hi=1e8+7;
		while(hi-lo>1){
			long long mid=(hi+lo)/2;
			if(isok(mid))lo=mid;
			else hi=mid;
		}
		printf("%lld\n",lo);
	}
	return 0;
}

