//tag: game
#include<cstdio>
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N,M;
        int ans=0;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N*M;++i){
            int x;
            scanf("%d",&x);
            ans+=x;
        }
        if(ans&1)printf("yadang\n");
        else printf("xiawa\n");
    }
    return 0;
}

