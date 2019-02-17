#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+7;
int x[MAXN],y[MAXN],z[MAXN];
long long ans=0;
void solve(int a[],int N){
	sort(a,a+N);
	int mid=N/2;
	for(int i=0;i<N;++i)
		ans+=abs(a[mid]-a[i]);
}
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	solve(x,N);
	solve(y,N);
	solve(z,N);
	printf("%lld\n",ans);
	return 0;
}

