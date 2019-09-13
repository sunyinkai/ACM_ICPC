//tag: union_set
#include<cstdio>
const int MAXN=5e4+7;
int par[MAXN];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void unit(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y)par[x]=y;
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)par[i]=i;
    for(int i=0;i<m;++i){
        int t,x,y;scanf("%d%d%d",&t,&x,&y);
        if(t==1){
            unit(x,y);
        }else{
            printf(find(x)==find(y)?"Yes\n":"No\n");
        }
    }
    return 0;
}
