#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int MAXN=1007,MAXM=10007;
const int INF=1e9+7;
struct data
{
    int st,en,val,next;
}es[MAXM],e[MAXM];
 
int head[MAXN],h[MAXN],tot,tot2;

bool vs[MAXN];
int dis[MAXN];
 
struct node{
    int id,len,h;
    bool operator <(const node &a)const{
        if(a.len+a.h==len+h) return a.len<len;
        else return a.len+a.h<len+h;
    }
};
 
void add_es2s(int st,int en,int val)
{
    es[tot].st=st;
    es[tot].en=en;
    es[tot].val=val;
    es[tot].next=head[st];
    head[st]=tot++;
}
 
void add_es2(int st,int en,int val)
{
    e[tot2].st=st;
    e[tot2].en=en;
    e[tot2].val=val;
    e[tot2].next=h[st];
    h[st]=tot2++;
}
 
/*对反向边求一次 dijstra ，求得各个点到终点的最短距离，也就是我们 A* 的估价函数中的 h 函数*/
void dijstra(int st,int n){
    memset(vs,0,sizeof(vs));
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    for(int i=h[st];i!=-1;i=e[i].next){
        dis[e[i].en]=e[i].val;
    }
    dis[st]=0;
    while(1){
        int k=-1 , Min=INF;
        for(int i=1;i<=n;i++)
            if(!vs[i] && dis[i]<Min){
                k=i;
                Min=dis[i];
            }
        if(k==-1) break;
        vs[k]=1;
        for(int i=h[k];i!=-1;i=e[i].next)
            if(!vs[e[i].en] && dis[e[i].en]>dis[k]+e[i].val)
                dis[e[i].en]=dis[k]+e[i].val;
    }
}
 
int kth_path(int s,int t,int k){
    if(dis[s]==INF) return -1;
    if(s==t) k++;
    priority_queue<node>q;
    node now;
    now.id=s; now.len=0; now.h=dis[s];
    q.push(now);
    int cnt=0;
    while(!q.empty()){
        node now=q.top(); q.pop();
        if(now.id==t) cnt++;
        if(cnt==k) return now.len;
        for(int i=head[now.id];i!=-1;i=es[i].next){
            node new_v;
            new_v.id=es[i].en; new_v.len=now.len+es[i].val; new_v.h=dis[es[i].en];
            q.push(new_v);
        }
    }
    return -1;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int s,e,k,T;scanf("%d%d%d%d",&s,&e,&k,&T);
		memset(head,-1,sizeof(head));
		memset(h,-1,sizeof(h));
		tot=tot2=0;
		for(int i=1;i<=m;i++){
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			add_es2s(a,b,t);
			add_es2(b,a,t);
		}
		dijstra(e,n);
		int ans=kth_path(s,e,k);
		if(ans<=T){
			printf("yareyaredawa\n");
		}else{
			printf("Whitesnake!\n");
		}
	}
    return 0;
}
