#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
struct node{
    int to,next;
}es[MAXN];
int tot,head[MAXN];
void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
void addEdge(int u,int v){
    es[tot].to=v;
    es[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u,int prev){
    for(int i=head[u];~i;i=es[i].next){
        if(u==prev)continue;
        int v=es[i].to;
        dfs(v,u);
    }
}

int main(){

    return 0;
}
