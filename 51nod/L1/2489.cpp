//tag: math
#include<cstdio>
int main(){
    int x;scanf("%d",&x);
    int lo=-1,hi=10000;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(mid*mid<=x)lo=mid;
        else hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
