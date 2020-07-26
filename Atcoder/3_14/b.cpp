#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    long long x,y;scanf("%lld%lld",&x,&y);
    if(x==1||y==1){
        printf("1\n");
        return 0;
    }

    long long ans=x*y;
    printf("%lld\n",ans%2==1?ans/2+1:ans/2);
    return 0;
}
