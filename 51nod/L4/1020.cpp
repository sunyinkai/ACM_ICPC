//tag: dp
#include<algorithm>
#include<cstdio>
const int MAXN=1e3+7;
const int MAXK=2e4+7;
const int mod=1e9+7;
int  dp[MAXN][MAXK];
void init(){
    for(int i=1;i<MAXN;++i)dp[i][0]=1;
    for(int i=2;i<MAXN;++i){
        for(int j=1;j<MAXK;++j){
          if(j>=i)dp[i][j]=(((dp[i][j-1]%mod+dp[i-1][j]%mod)%mod-dp[i-1][j-i]%mod)%mod+mod)%mod;
          else dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j]%mod)%mod;
        }
    }
}
int main(){
    init();
    int T;scanf("%d",&T);
    while(T--){
        int n,k;scanf("%d%d",&n,&k);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}
