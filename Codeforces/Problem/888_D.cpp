//tag: math

#include<cstdio>
long long C(int x,int y){
    long long ans=1;
    for(int i=1;i<=y;++i)ans=(long long)ans*(x-i+1);
    for(int i=1;i<=y;++i)ans/=i;
    return ans;
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    long long ans=0;
    if(k>=1)ans=1;
    if(k>=2)ans+=(long long)C(n,2);
    if(k>=3)ans+=(long long)2*C(n,3);
    if(k>=4)ans+=(long long)9*C(n,4);
    if(n<k)ans=0;
    printf("%lld\n",ans);
    return 0;
}
