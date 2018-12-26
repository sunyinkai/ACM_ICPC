#include<bits/stdc++.h>
using namespace std;
const int MAXN=2007;
const long long INF=1e13+7;

long long a[MAXN],b[MAXN];
long long sum[MAXN];
long long ans[MAXN][MAXN];
long long no[MAXN*3];
int main(){
	long long N,M;scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;++i)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=M;++i)scanf("%lld",&b[i]);
	long long x;scanf("%lld",&x);

	long long res=0;
	for(int i=1;i<=2*M;++i)no[i]=INF;

	for(int i=1;i<=M;++i)
		for(int j=i;j<=M;++j){
			ans[i][j]=ans[i][j-1]+b[j];
			no[j-i+1]=min(no[j-i+1],ans[i][j]);//这个长度能获得的最小答案
		}

	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;++j){
			long long  val=sum[j]-sum[i-1];
			long long t=x/val;
			int p=upper_bound(no+1,no+M+1,t)-no;
			--p;
			res=max(res,(long long)(j-i+1)*p);
		}
	}
	printf("%lld\n",res);
	return 0;

}
