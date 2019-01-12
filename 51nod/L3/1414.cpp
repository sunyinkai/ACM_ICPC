#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+7;
const int INF=1e9+7;
int N,ans=-INF;
int a[MAXN];
void solve(int len){
	if(N/len<3)return;
	//N/len边数
	for(int i=1;i<=len;++i){
		int sum=0;
		for(int j=i;j<=N;j+=len)
			sum+=a[j];
		ans=max(ans,sum);
	}
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]),ans+=a[i];
	for(int i=1;i*i<=N;++i){
		if(N%i==0){
			solve(N/i);
			solve(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}

