#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
const long long INF=1e18+1e10;
long long a[MAXN];
long long ans[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N/2;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<=N/2;++i){
		int last=N-i+1;
		if(i==1)ans[1]=0,ans[last]=a[i];
		else{
			long long t=min(ans[last+1],a[i]);
			if(a[i]-t>=ans[i-1]){
				ans[last]=t;
				ans[i]=a[i]-t;
			}else{
				ans[i]=ans[i-1];
				ans[last]=a[i]-ans[i];
			}
		}
	}

	for(int i=1;i<=N;++i)
		printf("%lld ",ans[i]);
	return 0;
}
