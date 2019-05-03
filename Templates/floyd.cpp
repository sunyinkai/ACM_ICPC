//hihocoder 1089
#include<cstdio>
#define min(a,b) (a<b?a:b)

const int MAXN=107;
const int INF=1e9+7;
int dp[MAXN][MAXN];

int main(){
    int N,M;scanf("%d%d",&N,&M);
    //input and init
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            dp[i][j]=(i==j?0:INF);
    for(int i=0;i<M;++i){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        dp[x][y]=dp[y][x]=min(dp[x][y],z);
    }
    //floyd
    for(int k=1;k<=N;++k)
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    //output
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j)
            printf("%d ",dp[i][j]);
        printf("\n");
    }
    return 0;
}
