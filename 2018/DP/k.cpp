#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=57;
const int INF=1e9+7;
int sum[MAXN];
int dp[MAXN][MAXN];

int main(){
    int L;
    int test=1;
    while(~scanf("%d",&L)&&L){
        int N;scanf("%d",&N);
        for(int i=1;i<=N;++i)scanf("%d",&sum[i]);
        sum[0]=0;
        
        sum[N+1]=L;
//       for(int i=1;i<=N+1;++i)dp[i][i]=sum[i]-sum[i-1];
        for(int i=N+1;i>=1;--i){
            for(int j=i+1;j<=N+1;++j){
                int res=INF;
                for(int k=i;k+1<=j;++k){
                    res=min(res,dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                }
                dp[i][j]=res;
//             printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        printf("The minimum cutting is %d.\n",dp[1][N+1]);
        ++test;
    }
    return 0;
}