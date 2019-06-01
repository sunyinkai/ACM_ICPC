#include<cstdio>
#define max(a,b) (a>b?a:b)
const long long mod=1e9+7;
const int MAXN=1e5+7;
const int MAXM=107;

long long M,B,N;
long long dp[MAXM],pre_sum[MAXM];

int main(){
    scanf("%lld%lld%lld",&M,&B,&N);
    //init
    int t=0;
    for(int i=0;i<=M;++i){
        if(i<=B){
            pre_sum[i]=i+1;
            dp[i]=1;
        }
        else{
            dp[i]=0;
            pre_sum[i]=pre_sum[i-1];
        }
    }
    for(int i=2;i<=N;++i){
        for(int j=0;j<=M;++j){
            dp[j]=pre_sum[j]-pre_sum[max(j-B,0) -1];
            pre_sum[j]=pre_sum[j-1]+dp[j];
            dp[j]%=mod;
            pre_sum[j]%=mod;
        }
    }
    printf("%lld\n",dp[M]);
    return 0;
}
