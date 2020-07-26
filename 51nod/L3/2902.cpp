//tag: union-find algorithm
#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int par[MAXN];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N,M;scanf("%d%d",&N,&M);
        for(int i=1;i<=N;++i)par[i]=i;
        bool isok=true;
        for(int i=0;i<M;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            x=find(par[x]);
            y=find(par[y]);
            if(x==y){
                isok=false;
            }else{
                par[x]=y;
            }
        }
        printf(isok?"No\n":"Yes\n");
    }
    return 0;
}
