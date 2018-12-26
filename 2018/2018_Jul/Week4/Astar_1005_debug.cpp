#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=1e4+7;
int dp[MAXN][MAXN];
int a[MAXN];
const long long mod=1e9+7;
int ans[MAXN];

int bit[MAXN][MAXN],N;
inline int lowbit(int i){
    return i&-i;
}

int sum(int len,int x){
    int res=0;
    while(x){
        res=(res+bit[len][x])%mod;
        x-=lowbit(x);
    }
    return res;
}
void add(int len,int p,int x){
    x%=mod;
    while(p<=N){
        bit[len][p]=(bit[len][p]+x)%mod;
        p+=lowbit(p);
    }
}

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        scanf("%d",&N);
        for(int i=1;i<=N;++i)scanf("%d",&a[i]);
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
                dp[i][j]=bit[i][j]=0;
        memset(ans,0,sizeof(ans));
        //dp[i][j]:以a[i]结尾的长度为j的个数
        for(int i=1;i<=N;++i){
            dp[i][1]=1;
            add(1,a[i],1);
            for(int j=2;j<=i;++j){
				int x=0;
                x=(x+sum(j-1,a[i]-1))%mod;
                dp[i][j]=(dp[i][j]+sum(j-1,a[i]-1))%mod;
				printf("x=%d,dp[%d][%d]=%d\n",x,i,j,dp[i][j]);
                ans[j]=(ans[j]+dp[i][j])%mod;
                add(j,a[i],dp[i][j]);
            }
        }
        ans[1]=N;
        printf("Case #%d:",test);
        for(int i=1;i<=N;++i)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
