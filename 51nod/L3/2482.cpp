//tag: math,logic,binary_search
#include<cstdio>
#define min(a,b) (a<b?a:b)

const long long INF=1e18+7;

int main(){
    long long num;scanf("%lld",&num);
    //case:1+x=num
    long long ans=num-1;
    //case 2: 1+x+x^2=num
    long long lo=0,hi=1e9+7;
    auto func=[](long long x){return 1+x+x*x;};
    while(hi-lo>1){
        long long mid=(hi+lo)/2;
        if(func(mid)>=num)hi=mid;
        else lo=mid;
    }
    if(func(hi)==num){
        ans=min(ans,hi);
    }
    //case 3: 1+k+k^2+k^3+...k^n
    for(long long k=2;k<=1e6;++k){
        long long t=1+k;
        long long base=k*k;
        for(long long len=3;len<=1e6;++len){
            t+=base;
            if(t>=num){
                if(t==num){
                    ans=min(ans,k);
                }
                break;
            }
            if(base>=INF/k)break;
            base*=k;
        }
    }
    //case 4: num=1
    if(num==1)ans=2;
    printf("%lld\n",ans);
    return 0;
}
