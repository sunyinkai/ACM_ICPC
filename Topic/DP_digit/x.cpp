#include<cstdio>
#include<cstring>
const int MAXN=20;
long long dp[MAXN];
long long ans[10];
int digit[MAXN];
long long power(long long base,long long n){
    long long res=1;
    for(int i=0;i<n;++i)res*=base;
    return res;
}

long long dfs(int len,bool lead,bool limit,int val){
    if(len==-1)return 0;
    if(!limit&&!lead&&dp[len])return dp[len];
    int up=limit?digit[len]:9;

    long long ans=0;
    for(int i=0;i<=up;++i){
        if(!(lead&&i==0)&&val==0){//不是前导0
            if(i==val)ans+=power(10,len);
        }
        else{
            if(i==val)ans+=power(10,len);
        }
        ans+=dfs(len-1,lead&&i==0,limit&&i==up,val);
    }
    if(!limit&&!lead)dp[len]=ans;
    return ans;
}

long long solve(long long x,int num){
    int tot=0;
    while(x){
        digit[tot++]=x%10;
        x/=10;
    }
    return dfs(tot-1,true,true,num);
}

int main(){
    long long l,r;scanf("%lld%lld",&l,&r);
    for(int i=0;i<=9;++i){
        memset(dp,0,sizeof(dp));
        printf("%lld ",solve(r,i));
        printf("%lld\n",solve(l-1,i));
    }
    return 0;
}
