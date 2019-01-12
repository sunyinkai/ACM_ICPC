#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
const long long mod=1e9+7;

int a[14]={0,1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[MAXN];
int main(){
	int N;scanf("%d",&N);
	dp[0]=1;
	for(int i=1;i<=13;++i)
		for(int j=a[i];j<=N;++j)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
	printf("%lld\n",dp[N]);
	return 0;
}
