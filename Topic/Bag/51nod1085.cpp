#include<cstdio>
#define max(a,b) (a>b?a:b)
const int  MAXN=100+7;
const int MAXM=1e4+7;
int c[MAXN],w[MAXN];
int dp[MAXM];
int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=0;i<N;++i){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=0;i<N;++i){
        for(int j=M;j>=c[i];--j){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    printf("%d\n",dp[M]);
    return 0;
}
