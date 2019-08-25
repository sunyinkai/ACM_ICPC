#include<cstdio>
int main(){
    int n,l,r;scanf("%d%d%d",&n,&l,&r);
    long long a=0;
    for(int i=0;i<n-l+1;++i)
        a+=1;
    long long val=2;
    for(int i=n-l+1;i<n;++i){
        a+=val;
        val*=2;
    }
    long long b=0;
    val=1;
    for(int i=0;i<r-1;++i){
        b+=val;
        val*=2;
    }
    for(int i=r-1;i<n;++i)
        b+=val;
    printf("%lld %lld\n",a,b);
    return 0;
}

