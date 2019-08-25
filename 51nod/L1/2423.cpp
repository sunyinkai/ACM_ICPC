//tag: tree
#include<cstdio>
const int MAXN=1007;
int du[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<N;++i){
        int x,y;scanf("%d%d",&x,&y);
        du[x]++;du[y]++;
    }
    int ans=0;
    for(int i=1;i<=N;++i)
        if(du[i]==1)++ans;
    if(du[1]==1)--ans;
    printf("%d\n",ans);
    return 0;
}
