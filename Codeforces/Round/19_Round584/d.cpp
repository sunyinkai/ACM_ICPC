#include<cstdio>
const int MAXN=1e5+7;
int par[MAXN];
int find(int x){
    return par[x]==x?par[x]:par[x]=find(par[x]);
}
bool unit(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        par[x]=y;
        return true;
    }
    return false;
}
int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)par[i]=i;
    int ans=0;
    for(int i=0;i<M;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        if(unit(x,y))++ans;
    }
    printf("%d\n",M-ans);
    return 0;
}
