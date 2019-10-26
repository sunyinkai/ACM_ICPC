#include<cstdio>
const int MAXN=1e3+7;
int par[MAXN];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
void unit(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b)par[a]=b;
}

int main(){
    int N,M;
    while(~scanf("%d",&N)&&N&&~scanf("%d",&M)){
        for(int i=1;i<=N;++i)par[i]=i;
        for(int i=0;i<M;++i){
            int a,b;scanf("%d%d",&a,&b);
            unit(a,b);
        }
        int ans=0;
        for(int i=1;i<=N;++i){
            if(i==find(i))++ans;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
