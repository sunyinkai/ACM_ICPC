#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
//在物品尽量多的情况下，容量尽可能大　


const int MAXM=9007;//50*180
const int MAXN=57;
const int INF=1e9+7;

int dp[MAXN][MAXM];
int a[MAXN];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n,t;scanf("%d%d",&n,&t);
		int sum=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		printf("Case %d: ",test);
		if(t>sum){
			printf("%d %d\n",n+1,sum+678);
		}else{
			for(int i=0;i<=n;++i)
				for(int j=0;j<=t;++j)
					dp[i][j]=-INF;
			dp[0][0]=0;
			//对于前i首歌中在第j分钟最多能唱多少首
			int res=0;
			for(int j=0;j<t;++j){//time
				for(int i=1;i<=n;++i){//song
					if(dp[i][j]>=0){
						if(j+a[i]<t){

						}
					}
				}
			}

			for(int i=1;i<=n;++i){
				for(int j=a[i];j<=t-1;++j){
					if(dp[i-1][j-a[i]]>=0||j==a[i]){
						dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+1);
						res=max(res,dp[i][j]);
					}
				}
			}

			printf("%d ",res+1);
			int sum=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=t-1;++j){
					if(dp[i][j]==res){
						sum=max(sum,j);
					}
				}
			}
			printf("%d\n",sum+678);
		}
	}
	return 0;
}
