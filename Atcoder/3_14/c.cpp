#include<cstdio>
int main(){
    long long a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
    if(c-(a+b)<0){
        printf("No\n");
        return 0;
    }
    long long x=4*a*b;
    long long y=(c-(a+b))*(c-(a+b));
    printf(x<y?"Yes\n":"No\n");
    return 0;
}
