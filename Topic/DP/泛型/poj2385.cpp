#include<cstdio>
#include<cstring>
#define max(a,b)  (a>b?a:b)
const int MAXT=1000+7,MAXW=37;
int T,W;
int dp[MAXT][MAXW][2];
int a[MAXT];
int main(){
	scanf("%d%d",&T,&W);
	for(int i=1;i<=T;++i){
		scanf("%d",&a[i]);
		a[i]-=1;
	}
	
	for(int i=1;i<=T;++i){
		for(int j=0;j<=W;++j){//已花费次数
			for(int k=0;k<=1;++k){
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+(a[i]==k));
				if(j>=1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][!k]+(a[i]==k));
			}
		}
	}
	printf("%d\n",max(dp[T][W][1],dp[T][W][0]));
	return 0;
}
