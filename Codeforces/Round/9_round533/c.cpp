#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
const long long mod=1e9+7;
long long dp[MAXN][3];

int main(){
	int n,l,r;scanf("%d%d%d",&n,&l,&r);

	long long cnt_0=0,cnt_1=0,cnt_2=0;
	if(r-l<=1e5){
		for(int i=l;i<=r;++i){
			if(i%3==0)++cnt_0;
			if(i%3==1)++cnt_1;
			if(i%3==2)++cnt_2;
		}
	}else{
		int begin=l/3*3;
		if(begin<l)begin+=3;

		int end=r/3*3;
		if(begin<end){//[begin,end)
			cnt_0=cnt_1=cnt_2=(end-begin)/3;
		}

		for(int i=l;i<begin;++i){
			if(i%3==0)++cnt_0;
			if(i%3==1)++cnt_1;
			if(i%3==2)++cnt_2;
		}

		for(int i=end;i<=r;++i){
			if(i%3==0)++cnt_0;
			if(i%3==1)++cnt_1;
			if(i%3==2)++cnt_2;

		}
	}

	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		dp[i][0]=(dp[i-1][0]*cnt_0+dp[i-1][1]*cnt_2+dp[i-1][2]*cnt_1)%mod;
		dp[i][1]=(dp[i-1][0]*cnt_1+dp[i-1][1]*cnt_0+dp[i-1][2]*cnt_2)%mod;
		dp[i][2]=(dp[i-1][0]*cnt_2+dp[i-1][1]*cnt_1+dp[i-1][2]*cnt_0)%mod;
	}

	printf("%lld\n",dp[n][0]);
	return 0;
}
