//tag: logic
#include<cstdio>
int main(){
    long long n,k,s;scanf("%lld%lld%lld",&n,&k,&s);
    if(k*(n-1)>=s&&s>=k)printf("YES\n");
    else printf("NO\n");
    return 0;
}
