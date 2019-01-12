#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+7;
const long long INF=1e14+7;
int a[MAXN];

int main(){
	int M,N;scanf("%d%d",&M,&N);
	for(int i=0;i<M;++i)
		scanf("%d",&a[i]);
	sort(a,a+M);

	long long sum=0,sum_2=0;
	for(int i=0;i<N;++i)
		sum+=a[i],sum_2+=a[i]*a[i];
	double average=sum*1.0/N;
	double t=sum_2+N*average*average-2*average*sum;
	long long ans=t;

	for(int i=N;i<M;++i){
		sum+=a[i]-a[i-N];
		sum_2+=a[i]*a[i]-a[i-N]*a[i-N];
		double average=sum*1.0/N;
		double t=sum_2+N*average*average-2*average*sum;
		ans=min(ans,(long long)t);
	}

	printf("%lld\n",ans);
	return 0;
}

