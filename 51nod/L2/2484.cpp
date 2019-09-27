//tag: dp
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1007;
const int INF=1e9+7;
int dp[MAXN][2];//当前处理到第i位,上面为上面0或者下面1的最小值.
int a[MAXN],b[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i)scanf("%d",&a[i]);
    for(int i=0;i<N;++i)scanf("%d",&b[i]);
        
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=0;i<N-1;++i){
        dp[i+1][0]=dp[i+1][1]=INF;
        if(a[i]<a[i+1]&&b[i]<b[i+1]){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
        }
        if(a[i]<b[i+1]&&b[i]<a[i+1]){
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1);
        }
        if(b[i]<a[i+1]&&a[i]<b[i+1]){
            dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
        }
        if(b[i]<b[i+1]&&a[i]<a[i+1]){
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1);
        }
    }
    printf("%d\n",min(dp[N-1][0],dp[N-1][1]));
    return 0;
}
