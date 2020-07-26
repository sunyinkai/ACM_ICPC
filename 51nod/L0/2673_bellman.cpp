#include<cstdio>
const int MAXM=5e4+7;
const int MAXN=507;
const int INF=1e9+7;
struct edge{
    int u,v,c;
}es[MAXM];

int d[MAXN];
int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
    }
    for(int i=1;i<=N;++i)d[i]=INF;
    int s,t;scanf("%d%d",&s,&t);
    d[s]=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(d[es[j].v]>d[es[j].u]+es[j].c)
                d[es[j].v]=d[es[j].u]+es[j].c;
            if(d[es[j].u]>d[es[j].v]+es[j].c)
                d[es[j].u]=d[es[j].v]+es[j].c;
        }
    }
    printf("%d\n",d[t]);
    return 0;
}
