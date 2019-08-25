//tag: math
#include<cstdio>
long long dp[4][int(1e6)];
long long akm(int m,int n){
    if(dp[m][n])return dp[m][n];
    if(m==0)return dp[m][n]=n+1;
    else if(m>0&&n==0)return dp[m][n]=akm(m-1,1);
    else if(m>0&&n>0)return dp[m][n]=akm( m-1 , akm( m,n-1 ) );
}

int main(){
    int m,n;scanf("%d%d",&m,&n);
    long long ans=akm(m,n);
    printf("%lld\n",ans);
    return 0;
}
