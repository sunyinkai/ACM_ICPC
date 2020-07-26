#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        long long a,b,n,m;
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        if(a+b<n+m){
            printf("No\n");
        }else{
            long long t=min(min(min(a,b),n),m);
            a-=t;b-=t;n-=t;m-=t;
            if(a==0){
                if(m)printf("No\n");
                else{
                    if(b<n)printf("No\n");
                    else printf("Yes\n");
                }
            }else if(b==0){
                if(m)printf("No\n");
                else{
                    if(a<n)printf("No\n");
                    else printf("Yes\n");
                }
            }else if(n==0){
                if(min(a,b)<m)printf("No\n");
                else printf("Yes\n");
            }else if(m==0){
                if(a+b<n)printf("No\n");
                else printf("Yes\n");
            }
        }
    }
    return 0;
}
