#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
const int mod=1e9;
long long  dp[MAXN];int tot=0;
int a[50];
int N;
void init(){
	a[0]=1;
	for(int i=1;;++i){
		a[i]=a[i-1]*2;
		if(a[i]>N){
			tot=i;
			break;
		}
	}
}
int main(){
	scanf("%d",&N);
	init();
	memset(dp,0,sizeof(dp));
	/*for(int i=1;i<=N;++i){
		 dp[i]=sigma( dp[i-a[j]] ),dp[0]=1;
		for(int j=0;a[j]<=i&&j<tot;++j){
				dp[i]=(dp[i]+dp[i-a[j]])%mod;有顺序问题
		}
		printf("dp[%d]=%lld\n",i,dp[i]);
	}*/
	dp[0]=1;
	for(int i=0;i<tot;++i){
		for(int j=a[i];j<=N;++j){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	printf("%lld\n",dp[N]%mod);
	return 0;
}
