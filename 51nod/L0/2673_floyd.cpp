#include<cstdio>
const int MAXN=507;
const int INF=1e9+7;
int dp[MAXN][MAXN];

int min(int x,int y){
    return x<y?x:y;
}
int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            dp[i][j]=(i==j?0:INF);
    for(int i=0;i<M;++i){
        int x,y,z;scanf("%d%d%d",&x,&y,&z);
        dp[x][y]=dp[y][x]=min(dp[x][y],z);
    }
    int s,t;scanf("%d%d",&s,&t);
    for(int k=1;k<=N;++k){
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    printf("%d\n",dp[s][t]);
    return 0;
}
