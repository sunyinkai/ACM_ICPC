#include<cstdio>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
const int INF=1e9+7;

int a[MAXN];//原数组
int b[MAXN];//改变后的数组
int dp[MAXN][2];//当前处理到第i位,0为不改变,1为改变的最小代价
//策略:只把数字改小
//case:6 7 8 4 5 6 7

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&a[i]);
    dp[0][0]=0;a[0]=0;
    dp[0][1]=1;b[0]=1;

    for(int i=1;i<=N;++i){
        //dp[i][1]:
        int x=dp[i-1][1],y=dp[i-1][0];
        if(x<y){
            b[i]=b[i-1]+1;
        }
        else if(x>y){
            b[i]=a[i-1]+1;
        }else{//x==y
            b[i]=min(a[i-1],b[i-1])+1;
        }
        dp[i][1]=min(x,y)+1;

        //dp[i][0]:
        int min_cost=INF;
        if(a[i]>a[i-1])min_cost=min(min_cost,dp[i-1][0]);
        if(a[i]>b[i-1])min_cost=min(min_cost,dp[i-1][1]);

        dp[i][0]=min_cost;
        printf("b[%d]:%d\n",i,b[i]);
        printf("dp[%d][0]:%d,dp[%d][1]:%d\n",i,dp[i][0],i,dp[i][1]);
    }
    printf("%d\n",min(dp[N][0],dp[N][1]));
    return 0;
}
