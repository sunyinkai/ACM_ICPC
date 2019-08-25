#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN],b[MAXN];
long long dp[MAXN][2];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        int x;scanf("%d",&x);
        a[i]=abs(1-x);//the cost of 1
        b[i]=abs(-1-x);// the cost of -1
    }
    dp[1][0]=a[1];dp[1][1]=b[1];
    for(int i=2;i<=N;++i){
        dp[i][0]=min(dp[i-1][0]+a[i],dp[i-1][1]+b[i]);
        dp[i][1]=min(dp[i-1][0]+b[i],dp[i-1][1]+a[i]);
 //       printf("%d %d\n",dp[i][0],dp[i][1]);
    }
    printf("%lld\n",dp[N][0]);
    return 0;
}
