//tag: logic
#include<cstdio>
const int MAXN=1e5+7;
const long long mod=1e9+7;
long long a[MAXN];
int main(){
    long long sum=0;
    long long ans=0;
    int N;scanf("%d",&N);
    long long prev=0;
    for(int i=1;i<=N;++i){
        scanf("%lld",&a[i]);
        prev+=a[i];
        sum+=prev;
        sum%=mod;
        prev%=mod;
    }
    for(int i=1;i<=N;++i){
        ans=(ans+sum)%mod;
        sum=((sum-(N-i+1)*a[i])%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
