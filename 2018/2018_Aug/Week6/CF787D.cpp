#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

typedef long long LL;
const int MAXN=5e5+7;
const long long  INF=1e15+7;
typedef pair<long long,int> P;
vector<P>G[MAXN];
int N,Q,S;
int mp[MAXN<<2],tot;
void addEdge(int a,int b,int c){
	G[a].push_back(P(c,b));
}

void build(int l,int r,int rt){
	mp[rt]=++tot;
	if(l==r)return ;
	int m=(l+r)/2;
	build(lson);
	build(rson);
}

LL d[MAXN];int done[MAXN];
priority_queue<P,vector<P>,greater<P> >q;
void build2(int l,int r,int rt){
	if(l==r){
		addEdge(mp[rt]+tot,mp[rt],0);
		addEdge(mp[rt],mp[rt]+tot,0);
		return ;
	}

	addEdge(mp[rt],mp[rt<<1],0);
	addEdge(mp[rt],mp[rt<<1|1],0);
	addEdge(mp[rt<<1]+tot,mp[rt]+tot,0);
	addEdge(mp[rt<<1|1]+tot,mp[rt]+tot,0);
	int m=(l+r)/2;
	build2(lson);
	build2(rson);
}
int que[MAXN],top;
void query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		que[top++]=mp[rt];
		return ;
	}
	int m=(l+r)/2;
	if(L<=m)query(L,R,lson);
	if(R>m)query(L,R,rson);
}

void dijkstra(int s){
	for(int i=1;i<=2*tot+10;++i)d[i]=INF,done[i]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
	//	printf("u=%d\n",u);
		done[u]=1;
		d[u]=p.first;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].second;
		//	printf("d[%d]=%d\n",v,d[v]);
			if(d[v]>d[u]+G[u][i].first){
				d[v]=d[u]+G[u][i].first;
				q.push(P(d[v],v));
			}
		}
	}

	for(int i=1;i<=N;++i){
		top=0;query(i,i,1,N,1);
		int x=que[0];
		if(d[x]==INF)printf("-1 ");
		else printf("%lld ",d[x]);
	}
}
int main(){
	scanf("%d%d%d",&N,&Q,&S);
	tot=0;
	build(1,N,1);
	//printf("tot=%d\n",tot);
	build2(1,N,1);//建图
	while(Q--){
		int t;scanf("%d",&t);
		if(t==1){
			int v,u,w;scanf("%d%d%d",&v,&u,&w);
			top=0;query(v,v,1,N,1);
			int x=que[0]+tot;
			top=0;query(u,u,1,N,1);
			int y=que[0];
			addEdge(x,y,w);
		}else{
			int v,l,r,w;scanf("%d%d%d%d",&v,&l,&r,&w);
			if(t==2){//v->[l,r];
				top=0;query(v,v,1,N,1);
				int x=que[0];
				top=0;query(l,r,1,N,1);
				for(int i=0;i<top;++i){
					addEdge(x+tot,que[i],w);
					//printf("%d -> %d %d\n",x,que[i],w);
				}
			}else{//[l,r] -> v
				top=0;query(v,v,1,N,1);
				int x=que[0];
				top=0;query(l,r,1,N,1);
				for(int i=0;i<top;++i){
					addEdge(que[i]+tot,x,w);
					//printf("%d -> %d %d\n",que[i]+tot,x,w);
				}
			}
		}
	}

	top=0;query(S,S,1,N,1);
	int x=que[0]+tot;
	dijkstra(x);
	return 0;
}
