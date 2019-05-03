//tag: dp,logic
#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
const int MAXN=5e4+7;
int a[MAXN];
int dp[MAXN][2];

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&a[i]);
    int ans=0;
    //不选择a[1]:a[2]...a[N]任意选
    dp[2][1]=a[2];
    for(int i=3;i<=N;++i){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    }
    ans=max(dp[N][0],dp[N][1]);
    //选择a[1]:a[N],a[2]不可以选
    memset(dp,0,sizeof(dp));
    dp[2][0]=a[1];
    for(int i=3;i<=N-1;++i){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    }
    ans=max(max(ans,dp[N-1][0]),dp[N-1][1]);
    printf("%d\n",ans);
    return 0;
}
