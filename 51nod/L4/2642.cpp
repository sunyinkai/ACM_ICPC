//tag: brute_force
#include<cstdio>
#include<algorithm>
using namespace std;
bool isok(int x){
    int i=2;
    for(;i*i<=x;++i){
        if(x%i==0)break;
    }
    return i*i>x;
}
int main(){
    int x;scanf("%d",&x);
    int ans=0;
    for(int i=1;i+i<=x;++i){
        if(isok(i)&&isok(x-i)){
            ans=max(ans,i*(x-i));
        }
    }
    printf("%d\n",ans);
    return 0;
}
