#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN=1007;
const LL INF=1e15+7;
struct node{
	LL now,cnt,dis;
	node(){}
	node(LL _now,LL _cnt,LL _dis){
		now=_now;cnt=_cnt;dis=_dis;
	}
	bool operator<(const node&other)const{
		return dis<other.dis;
	}
};

struct two{
	LL x,p;
	two(LL a=0,LL b=0){x=a;p=b;}
};

vector<two>G[MAXN];

struct edge{
	LL to,next,cost;
}es[MAXN*4+7];
LL dp[MAXN][MAXN];//从1到i经过j个点的最短路
LL tot,head[MAXN];
int done[MAXN][MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(LL a,LL b,LL c){
	es[tot].to=b;
	es[tot].cost=c;
	es[tot].next=head[a];
	head[a]=tot++;
}

int main(){
	LL N,M,Q;scanf("%lld%lld%lld",&N,&M,&Q);
	init();
	for(LL i=1;i<=M;++i){
		LL a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}
	for(LL i=0;i<=N;++i)
		for(LL j=0;j<=N;++j)
			dp[i][j]=INF;
	priority_queue<node>q;
	dp[1][0]=0;
	q.push(node(1,0,0));
	while(!q.empty()){
		node u=q.top();q.pop();
		done[u.now][u.cnt]=0;
		for(LL i=head[u.now];~i;i=es[i].next){
			LL v=es[i].to;
			LL cnt=u.cnt;
			if(dp[v][cnt+1]>dp[u.now][cnt]+es[i].cost){
				dp[v][cnt+1]=dp[u.now][cnt]+es[i].cost;
				if(!done[v][cnt+1]){
					done[v][cnt+1]=1;
					q.push(node(v,cnt+1,dp[v][cnt+1]));
				}
			}
		}
	}
	for(int i=1;i<=N;++i){
		LL minn=INF;
		for(int j=0;j<=N;++j){
			if(dp[i][j]<minn){
				minn=dp[i][j];
				G[i].push_back(two(dp[i][j],j));
			}
		}
	}
	while(Q--){
		LL to,day;scanf("%lld%lld",&to,&day);
		LL minn=INF;
		if(to==1){
			printf("0\n");
			continue;
		}else{
			for(int j=0;j<G[to].size();++j)minn=min(minn,G[to][j].x+G[to][j].p*day);//p为经过的点数，x为不加权距离
		}
		printf("%lld\n",minn);
	}
	return 0;
}
