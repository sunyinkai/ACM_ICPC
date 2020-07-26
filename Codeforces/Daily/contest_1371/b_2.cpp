#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        long long N,M;scanf("%lld%lld",&N,&M);
        long long t=min(N,M);
        long long ans=(1+t)*t/2;
        if(N<=M)ans=ans-N+1;
        printf("%lld\n",ans);
    }
    return 0;
}
