#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1007;
char s[MAXN],t[MAXN];
int dp[MAXN][MAXN];
const int mod=10007;
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%s",s+1);
		int N=strlen(s+1);
		for(int i=1;i<=N;++i){
			t[i]=s[i];
		}
		reverse(t+1,t+N+1);
		t[N+1]='\0';
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				if(s[i]==t[j]){
					dp[i][j]+=dp[i-1][j-1]+1;
				}
				dp[i][j]%=mod;
				printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
			}
		}
		printf("%d\n",dp[N][N]%mod);
	}
	return 0;
}
