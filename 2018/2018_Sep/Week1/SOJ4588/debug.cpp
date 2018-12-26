#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int MAXN=1e6+7,MAXM=1e6+7;
const int INF=1e9+7;

int a[MAXM],b[MAXM],c[MAXM];
int dis0[MAXN],dis2[MAXN],done[MAXN];
int N,M;
vector<P>G[MAXN];

void dijkstra(int* d,int s){
    for(int i=1;i<=N;++i)d[i]=INF,done[i]=0;
    d[s]=0;
    priority_queue<P,vector<P>,greater<P> >q;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top();q.pop();
        int u=p.second;
        if(done[u])continue;
        done[u]=1;
        d[u]=p.first;
        int len=G[u].size();
        for(int i=0;i<len;++i){
            int v=G[u][i].second;
            if(d[v]>d[u]+G[u][i].first){
                d[v]=d[u]+G[u][i].first;
                q.push(P(d[v],v));
            }
        }
    }
}
inline int read(){
    char ch;
    while(1){
        ch=getchar();
        if(!isspace(ch))break;
    }
    int res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')res=res*10+ch-'0';
    return res;
}

int main(){
	//freopen("input.txt","r",stdin);
    int T;T=read();
    while(T--){
		N=read();M=read();
        for(int i=0;i<M;++i)a[i]=read(),b[i]=read(),c[i]=read();
        for(int i=1;i<=N;++i)G[i].clear();
        for(int i=0;i<M;++i){
            G[a[i]].push_back(P(2-c[i],b[i]));
            G[b[i]].push_back(P(2-c[i],a[i]));
        }
        dijkstra(dis0,N);
        for(int i=1;i<=N;++i)G[i].clear();
        for(int i=0;i<M;++i){
            if(c[i]<=1){
                G[a[i]].push_back(P(1-c[i],b[i]));
                G[b[i]].push_back(P(1-c[i],a[i]));
            }
        }

        dijkstra(dis2,1);
        int res=INF;
        for(int i=1;i<=N;++i){
            //printf("dis0[%d]=%d,dis2[%d]=%d\n",i,dis0[i],i,dis2[i]);
            res=min(res,dis0[i]+dis2[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
