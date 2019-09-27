#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=107;
const int MAXM=5e4+7;
int c[MAXN],v[MAXN];
int dp[MAXN][MAXM];
int main(){
    int N,V;scanf("%d%d",&N,&V);
    for(int i=1;i<=N;++i){
        scanf("%d%d",&c[i],&v[i]);
    }
    for(int i=1;i<=N;++i){
        for(int j=0;j<=V;++j){
            if(j<c[i])dp[i][j]=dp[i-1][j];
            else  dp[i][j]=max(dp[i-1][j],dp[i][j-c[i]]+v[i]);
        }
    }
    printf("%d\n",dp[N][V]);
    return 0;
}
