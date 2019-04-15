//tag: greedy
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+7;
int a[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	sort(a,a+N);
	int i=0,j=N-1;
	int ans=0;
	while(i<=j){
		if(i==j){++ans;break;}
		if(a[i]+a[j]<=M)++ans,++i,--j;
		else --j,++ans;
	}
	printf("%d\n",ans);
	return 0;
}
