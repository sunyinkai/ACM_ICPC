#include<cstdio>
#include<cstring>
const int MAXN=207;
int N;
int vis[MAXN];
int b[MAXN];
int ans[MAXN],tot;

int getVal(int x){
    int ans=-1;
    for(int i=x;i<=2*N;++i){
        if(vis[i])continue;
        else{
            ans=i;
            vis[i]=1;
            break;
        }
    }
    return ans;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%d",&N);
        for(int i=1;i<=N;++i){
            scanf("%d",&b[i]);
            vis[b[i]]=1;
        }

        tot=0;
        int hasAns=true;
        for(int i=1;i<=N;++i){
            ans[tot++]=b[i];
            int ret=getVal(b[i]);
            if(ret==-1){
                hasAns=false;
            }else{
                ans[tot++]=ret;
            }
        }
        if(hasAns){
            for(int i=0;i<tot;++i)
                printf("%d ",ans[i]);
            printf("\n");
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
