#include<cstdio>
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
const long long INF=1e18+7;
long long  n;
long long res,miniNum;
void dfs(int depth,int precnt,long long  num,long long  cnt)
{
    if(cnt>res)
    {
        res=cnt;
        miniNum=num;
    }
    if(res==cnt&&num<miniNum)miniNum=num;
    if(depth==16)return;
    for(int i=1;i<64&&i<=precnt;++i)
    {
        if(num<=n/p[depth])
        {
            num*=p[depth];
 //           printf("depth+1=%d,num=%lld,cnt*(i+1)=%lld\n",depth+1,num,cnt*(i+1));
            dfs(depth+1,i,num,cnt*(i+1));
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        res=0,miniNum=INF;
        dfs(0,100,1,1);
        printf("%lld %lld\n",miniNum,res);
    }
}

