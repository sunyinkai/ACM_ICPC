#include<bits/stdc++.h>
using namespace std;
const int MAXN=6e6+9;
int f[MAXN],len[MAXN];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int head[MAXN],to[MAXN],nxt[MAXN],tot;
void addedge(int u,int v){
    to[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
}

bool vis[MAXN];
int dfs(int u){
    int tmp=0;
    for(int i=head[u];i;i=nxt[i]){
        if(vis[to[i]])continue;
        vis[to[i]]=true;
        tmp=max(tmp,dfs(to[i])+1);
    }
    return tmp;
}
int longpath(int u){
   // cout<<"in "<<u<<endl;
    queue<int> q;
    q.push(u);
    memset(vis,0,sizeof(vis));

    int v,d;
     vis[u]=true;
    while(!q.empty()){
        v=q.front();q.pop();
       // cout<<v<<endl;
       
        for(int i=head[v];i;i=nxt[i]){
           // cout<<"in"<<endl;
            if(!vis[to[i]])vis[to[i]]=true,q.push(to[i]);
        }
    }
    memset(vis,0,sizeof(vis));
    int len=dfs(v);
    //cout<<len<<endl;
    return len;
}

int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    memset(head,0,sizeof(head));
    tot=0;
    for(int i=0;i<=n;i++)f[i]=i;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
        u=find(u),v=find(v);
        f[u]=v;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==i)len[i]=longpath(i);
    }
    for(int i=0;i<q;i++){
        int t,x,y;
        scanf("%d",&t);
        if(t==1){
            scanf("%d",&x);
            printf("%d\n",len[find(x)]);
        }
        else {
            scanf("%d%d",&x,&y);
            x=find(x),y=find(y);
            if(x!=y){
               // cout<<len[x]<<' '<<len[y]<<endl;
                len[x]=max(len[x],max(len[y],(len[x]+1)/2+(len[y]+1)/2+1));
                f[y]=x;
            }
        }
    }
}

