#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1007;
int dp[MAXN][207];//当前状态为i,分数为j的状态
int a[MAXN],b[MAXN],c[MAXN];
int main(){
	int n,m,k,l;scanf("%d%d%d%d",&n,&m,&k,&l);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	//bad 0 tie 1 good 2
	for(int j=0;j<=200;++j){
		if(j>=k+100)dp[n+1][j]=2;
		else if(j<=l+100)dp[n+1][j]=0;
		else dp[n+1][j]=1;
	}

	for(int i=n;i>=0;--i){
		for(int j=0;j<=200;++j){
			int res;
			if(i&1){//当前为先手，先手想good
				res=0;
				if(a[i]){
					int nx=j+a[i];
					nx=min(nx,200);
					res=max(res,dp[i+1][nx]);
				}
				if(b[i]){
					int nx=j-b[i];
					nx=max(nx,0);
					res=max(res,dp[i+1][nx]);
				}
				if(c[i]){
					int nx=200-j;
					res=max(res,dp[i+1][nx]);
				}
			}else{//当前为后手，后手想bad
				res=2;
				if(a[i]){
					int nx=j+a[i];
					nx=min(nx,200);
					res=min(res,dp[i+1][nx]);
				}
				if(b[i]){
					int nx=j-b[i];
					nx=max(nx,0);
					res=min(res,dp[i+1][nx]);
				}
				if(c[i]){
					int nx=200-j;
					res=min(res,dp[i+1][nx]);
				}
			}
			dp[i][j]=res;
		}
	}
	if(dp[1][m+100]==2){
		printf("Good Ending\n");
	}else if(dp[1][m+100]==1){
		printf("Normal Ending\n");
	}else{
		printf("Bad Ending\n");
	}
	return 0;
}
