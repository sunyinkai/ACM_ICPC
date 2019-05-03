//tag: LIS,logic
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+7;
int a[MAXN],dp[MAXN];
int main(){
    int N;scanf("%d",&N);
    fill(dp,dp+N,INF);
    int ans=0,top=0;
    for(int i=1;i<=N;++i){
        int x;scanf("%d",&x);
        if(x-i<0)++ans;
        else{
            a[top++]=x-i;
        }
    }
    for(int i=0;i<top;++i)*upper_bound(dp,dp+top,a[i])=a[i];
    printf("%d\n",ans+top-(lower_bound(dp,dp+top,INF)-dp));
    return 0;
}
