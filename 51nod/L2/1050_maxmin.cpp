#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=4e5+7;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	int has_postive=0;
	long long sum=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>0)has_postive=1;
	}
	long long ans=0;
	if(!has_postive)ans=0;
	else{
		long long sum_max=0,ans_max=0;
		long long sum_min=0,ans_min=0;
		for(int i=1;i<=N;++i){
			if(sum_max<0)sum_max=0;
			if(sum_min>0)sum_min=0;
			sum_max+=a[i];
			sum_min+=a[i];
			ans_max=max(ans_max,sum_max);
			ans_min=min(ans_min,sum_min);
		}
		ans=max(ans_max,sum-ans_min);
	}
	printf("%lld\n",ans);
	return 0;
}
