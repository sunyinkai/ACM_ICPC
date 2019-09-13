//tag: logic
#include<cstdio>
const int INF=1e9+7;
int main(){
    int x,y;scanf("%d%d",&x,&y);
    int ans=0;
    while(x<y){
        if(y%2==0)y/=2;
        else y++;
        ++ans;
    }
    if(x>=y)ans+=x-y;
    printf("%d\n",ans);
    return 0;
}
