//三维空间上的最短路构图
//考虑球的关系
//G[i].clear()初始化 
//函数的返回值
//我 是ZZ :dis[i][j]-=r[i]-r[j];
//点数少floyd
#include<bits/stdc++.h>
using namespace std;
const int MAXN=107;
const double INF=1e9+7;
typedef pair<double,int> P;
int x[MAXN],y[MAXN],z[MAXN],r[MAXN];
double getDis(double x1,double y1,double z1,double x2,double y2,double z2){
	return sqrt( pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}

vector<P>G[MAXN];
int N,test=1;
double d[MAXN];
int done[MAXN];
double dijkstra(){
	for(int i=1;i<=N;++i)d[i]=INF;
	d[N-1]=0.0;
	priority_queue<P,vector<P>,greater<P> >q;
	while(!q.empty())q.pop();
	memset(done,0,sizeof(done));
	q.push(P(0.0,N-1));
	while(!q.empty()){
		P p=q.top();q.pop();
		int u=p.second;
		if(done[u])continue;
		d[u]=p.first;
	//	printf("d[%d]=%.2f\n",u,d[u]);
		done[u]=1;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].second;
			if(d[v]>d[u]+G[u][i].first){
				d[v]=d[u]+G[u][i].first;
				q.push(P(d[v],v));
			}
		}
	}
	//printf("d[N]=%.2f\n",d[N]);
	return d[N];
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&N)&~N){
		for(int i=1;i<=N;++i){
			scanf("%d%d%d%d",&x[i],&y[i],&z[i],&r[i]);
		}//N+1: s N+2: t
		for(int i=N+1;i<=N+2;++i)scanf("%d%d%d",&x[i],&y[i],&z[i]),r[i]=0;
		N+=2;
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=1;i<=N;++i){
			for(int j=i+1;j<=N;++j){
				double dis=getDis(x[i],y[i],z[i],x[j],y[j],z[j]);
				dis-=r[i]+r[j];
				if(dis<0)dis=0.0;//两个球相交
				G[i].push_back(P(dis,j));
				G[j].push_back(P(dis,i));
			}
		}
		double res=dijkstra()*10;
		printf("Cheese %d: Travel time = %d sec\n",test,(int)round(res));
		++test;
	}
	return 0;
}
