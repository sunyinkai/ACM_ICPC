#include<cstdio>
int main(){
    int T;scanf("%d",&T);
    while(T--){
        long long a,b,n;scanf("%lld%lld%lld",&a,&b,&n);
        if(n%3==0)printf("%lld\n",a);
        else if(n%3==1)printf("%lld\n",b);
        else printf("%lld\n",a^b);
    }
    return 0;
}
