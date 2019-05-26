#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    long long X,Y,H,D;
    scanf("%lld+%lld %lld+%lld",&X,&Y,&H,&D);
    if(X>=H+D){printf("%.2f\n",1.0);}
    else if(X+Y<H){printf("%.1f\n",0.0);}
    else{
        long long ans=0;
        //0
        int cnt=Y;
        if(X<=H){
            cnt-=(H-X);
            ans+=(1+min(cnt,D))*(min(cnt,D)+1)/2;
            cnt-=min(cnt,D);
            ans+=cnt*(D+1);
        }
        else{

        }
        printf("%.2f\n",1.0*ans/Y/D);
    }
    return 0;
}
