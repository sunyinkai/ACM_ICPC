//hihocoder1971
//最短路形成的DAG
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
const int MAXN=1007;
const int INF=1e9+7;

const int SIZ=409600;
inline char nc(){
    static char buf[SIZ],*p1=buf,*p2=buf;
    if(p1==p2)p2=(p1=buf)+fread(buf,1,SIZ,stdin);
    return p1==p2?EOF:*p1++;
}

int read(){
    int num=0;
    char ch;
    while((ch=getchar())>='0'&&ch<='9')num=num*10+ch-'0';
    return num;
}
struct edge{
    int to,cost,id;
    bool operator<(const edge&other)const{
        return cost>other.cost;
    }
};

vector<edge>G[MAXN];
int done[MAXN],d[MAXN];

int N,M;
void dijkstra(int s,int t){
    for(int i=1;i<=N;++i)d[i]=INF;
    d[s]=0;
    memset(done,0,sizeof(done));

    priority_queue<edge>q;
    q.push(edge{s,0,0});
    while(!q.empty()){
        const edge e=q.top();q.pop(); //这个地方千万不能加引用
        int u=e.to;
        if(done[u])continue;
        d[u]=e.cost;
        done[u]=1;

        int len=G[u].size();
        for(int i=0;i<len;++i){
            edge& es=G[u][i];
            if(d[es.to]>d[u]+es.cost){
                d[es.to]=d[u]+es.cost;
                q.push(edge{es.to,d[es.to],0});
            }
        }
    }
}

int isok[MAXN*MAXN];
void dfs(int u,int pre){
    if(u==1)return; //到了起点
    int len=G[u].size();
    for(int i=0;i<len;++i){
        const edge& e=G[u][i];
        if(e.to==pre)continue;
        if(d[e.to]+e.cost!=d[u])continue;
        isok[e.id]=1;
        dfs(e.to,u);
    }
}


int main(){
//    scanf("%d%d",&N,&M);
    N=read();M=read();
    for(int i=0;i<M;++i){
        int a,b,c;
        a=read();b=read();c=read();
 //       int a,b,c;scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(edge{b,c,i});
        G[b].push_back(edge{a,c,i});
    }

    dijkstra(1,N);
    //最短路DAG
    //case 1,沿这条路上任意走都是到某一点的最短路
    /*
    for(int i=0;i<M;++i){
        printf("%d-%d cost:%d\n",no[i].u,no[i].v,no[i].c);
        printf("%d  %d   %d\n",d[no[i].u],d[no[i].v],no[i].c);
        if(d[no[i].u]==d[no[i].v]+no[i].c || d[no[i].v]==d[no[i].u]+no[i].c){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    */
    //case 2,沿这条路上任意走都是走到终点的最短路
    memset(isok,0,sizeof(isok));
    dfs(N,-1);
    for(int i=0;i<M;++i)
        printf(isok[i]?"YES\n":"NO\n");
    return 0;
}
