#include<cstdio>
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}

int main(){
    int N;scanf("%d",&N);
    long long ans=0;
    for(int i=0;i<N;++i){
        long long x;scanf("%lld",&x);
        ans=gcd(ans,x);
    }
    int cnt=0;
    for(long long i=1;i*i<=ans;++i){
        if(ans%i==0){
            ++cnt;
            if(i*i!=ans){
                ++cnt;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
