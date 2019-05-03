//最长非下降子序列
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e3+7;
const int INF=1e9+7;
int a[MAXN],dp[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<N;++i)dp[i]=INF;
    for(int i=0;i<N;++i)
        *upper_bound(dp,dp+N,a[i])=a[i];
    printf("%d\n",lower_bound(dp,dp+N,INF)-dp);
    return 0;
}
