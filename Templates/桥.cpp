//求桥
//并查集判连通
//传边的编号防止重边


#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXV=1007;
const int MAXE=MAXV*MAXV;
const int INF=1e9+7;
struct edge{ 
	int to,next,cost;
}es[MAXE*2];

int tot,head[MAXV];
void init(){ 
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdg(int a,int b,int c){ 
	es[tot].cost=c;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
};
int par[MAXV];
int find(int x){ 
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){ 
	x=find(x);
	y=find(y);
	if(x!=y){ 
		par[x]=y;
	}
}
int time,low[MAXV],dfn[MAXV];
int res;
void dfs(int u,int pre){ 
	low[u]=dfn[u]=++time;
	for(int i=head[u];~i;i=es[i].next){ 
		int v=es[i].to;
		if((i^pre)==1)continue;
		if(!dfn[v]){ 
			dfs(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){//if is bridge
	//			printf("%d---- %d %d\n",u,v,es[i].cost);
				res=min(res,es[i].cost);
			}
		}else{ 
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){ 
	int N,M;
	while(~scanf("%d%d",&N,&M)&&N+M){ 
		init();
		for(int i=1;i<=N;++i)par[i]=i;

		for(int i=0;i<M;++i){ 
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			addEdg(a,b,c);
			addEdg(b,a,c);
			unit(a,b);
		}
		
		int cnt=0;
		for(int i=1;i<=N;++i){ 
			par[i]=find(par[i]);
			if(par[i]==i)++cnt;
		}

		if(cnt>=2){ 
			printf("0\n");
			continue;
		}

		time=0;
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		res=INF;
		dfs(1,-1);
		if(res==0)printf("1\n");
		else if(res==INF)printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}
