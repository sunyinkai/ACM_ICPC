#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM=1e5+7;
const int MAXN=1e5+7;
struct edge{
	int u,v,c;
	bool operator<(const edge&other)const{
		return c<other.c;
	}
}es[MAXM];

int a[MAXM];
int par[MAXM];
int find(int u){
	return par[u]==u?par[u]:par[u]=find(par[u]);
}

void unit(int x,int y){
	x=find(par[x]);
	y=find(par[y]);
	if(x!=y)par[x]=y;
}

struct edges{
	int to,cost;
	int id;
	edges(int v,int c,int idx){
		to=v;cost=c;id=idx;
	}
};

vector<edges>G[MAXN];
int du[MAXN];
int visit[MAXN];
int isok[MAXN];

int main(){
	int N,M,K;scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=K;++i){
		scanf("%d",&a[i]);
		visit[a[i]]=1;
	}

	for(int i=0;i<M;++i){
		scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].c);
	}
	sort(es,es+M);
	for(int i=1;i<=N;++i)par[i]=i;
	for(int i=0;i<M;++i){
		int x=es[i].u,y=es[i].v;
		int tx=find(x),ty=find(y);
		if(par[tx]!=par[ty]){
			unit(tx,ty);
			G[x].push_back(edges(y,es[i].c,i));
			G[y].push_back(edges(x,es[i].c,i));
			du[x]++;du[y]++;
			isok[i]=1;
		}
	}
	queue<int>q;
	for(int i=1;i<=N;++i){
		if(du[i]==1)q.push(i);
	}

	while(!q.empty()){
		int u=q.front();q.pop();
	//	printf("u=%d\n",u);
		if(visit[u])continue;
		int len=G[u].size();
		for(int i=0;i<len;++i){
			int v=G[u][i].to;
			du[v]--;
			//printf("no:%d\n",G[u][i].id);
			isok[G[u][i].id]=0;
			if(du[v]==1){
				q.push(v);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=M;++i){
		if(isok[i])ans=max(ans,es[i].c);
	}
	for(int i=0;i<K;++i)
		printf("%d ",ans);
	return 0;
}
