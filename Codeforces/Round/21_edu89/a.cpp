#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int a,b;scanf("%d%d",&a,&b);
        long long ans=0;
        while(a>1||b>1){
            printf("a:%d b:%d\n",a,b);
            if(a==0||b==0)break;
            if(a>b)swap(a,b);//a<=b
            if(2*a<=b){ans+=a;break;}
            if(a<=2&&b>=2){
                ans+=1;
                break;
            }
            else{
                int t=a/3;
                ans+=t*2;
                a-=t*3;
                b-=t*3;
           }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
