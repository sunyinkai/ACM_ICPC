//poj3255
//严格次短路
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=5007;
const int INF=1e9+7;
typedef pair<int,int>P;
vector<P>G[MAXN];
priority_queue<P,vector<P>,greater<P> >q;
int d[MAXN],d2[MAXN],done[MAXN];
int N,M;
void dijkstra(){
	while(!q.empty())q.pop();
	fill(d+1,d+N+1,INF);
	fill(d2+1,d2+N+1,INF);
	d[1]=0;
	q.push(P(d[1],1));//init

	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		int nowMin=p.first;
		if(d2[u]<nowMin)continue;//	取出的不是次短路
		int len=G[u].size();
		for(int i=0;i<len;++i){
			P &e=G[u][i];
			int v=e.second;
			int nextMin=nowMin+e.first;
			if(d[v]>nextMin){//最短路
				swap(d[v],nextMin);
				q.push(P(d[v],v));
			}
			//printf("v=%d,d[v]=%d,nextMin=%d,d2[v]=%d\n",v,d[v],nextMin,d2[v]);
			if(d2[v]>nextMin&&d[v]<nextMin){//次短路,严格次短路和非严格 <=非严格次短路
				d2[v]=nextMin;
				q.push(P(d2[v],v));
				//printf("->d2[v]=%d\n",d2[v]);
			}
		}
	}
	printf("%d\n",d2[N]);
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		G[a].push_back(P(c,b));
		G[b].push_back(P(c,a));
	}
	dijkstra();
	return 0;
}
