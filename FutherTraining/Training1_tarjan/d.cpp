#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define swap(a,b) (a^=b^=a^=b)
const int MAXE=2e5+7;
const int MAXV=1e5+7;
struct edge{
	int from,to,next;
	bool isCut;
}es[2][MAXE*2];
int head[2][MAXV],tot[2];
void init(){
	memset(head,-1,sizeof(head));
	memset(tot,0,sizeof(tot));
}
void addEdge(int k,int a,int b){
	es[k][tot[k]].to=b;
	es[k][tot[k]].isCut=0;
	es[k][tot[k]].from=a;
	es[k][tot[k]].next=head[k][a];
	head[k][a]=tot[k]++;
}
int low[MAXV],dfn[MAXV],time;
void dfs(int k,int u,int id){
	low[u]=dfn[u]=++time;
	for(int i=head[k][u];~i;i=es[k][i].next){
		if((i^1)==id)continue;//防止重边
		int v=es[k][i].to;
		if(!dfn[v]){
			dfs(k,v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				es[k][i].isCut=es[k][i^1].isCut=1;
			}
		}else low[u]=min(low[u],dfn[v]);
	}
}

int belong[MAXV];
int inline find(int x){
	return belong[x]==x?belong[x]:belong[x]=find(belong[x]);
}
void inline unit(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)belong[a]=b;
}
int depth[MAXV],par[MAXV],parID[MAXV];
void dfs2(int u,int pre,int id,int dep){
	par[u]=pre;parID[u]=id;depth[u]=dep;
	for(int i=head[1][u];~i;i=es[1][i].next){
		int v=es[1][i].to;
		if(v==pre)continue;
		dfs2(v,u,i,dep+1);
	}
}
int main(){
	int V,E,test=1;
	while(~scanf("%d%d",&V,&E)&&V+E){
		printf("Case %d:\n",test++);
		init();
		time=0;
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		for(int i=0;i<E;++i){
			int a,b;scanf("%d%d",&a,&b);
			addEdge(0,a,b);
			addEdge(0,b,a);
		}
		dfs(0,1,-1);//0为原图
		for(int i=1;i<=V;++i)belong[i]=i;
		for(int i=0;i<tot[0];i+=2){
			if(!es[0][i].isCut){//不是桥
				int u=es[0][i].from,v=es[0][i].to;
				unit(u,v);
			}
		}
		int edgeCnt=0;
		int root;
		for(int i=0;i<tot[0];i+=2){
			if(es[0][i].isCut){//把桥加上去
				++edgeCnt;
				int u=es[0][i].from,v=es[0][i].to;
				int a=find(u),b=find(v);
				addEdge(1,root=a,b);
				addEdge(1,b,a);//!!!必须找到缩点后的代表元
	//			printf("%d-%d\n",find(u),find(v));
			}
		}//缩点
	//	printf("root=%d\n",root);getchar();getchar();
		dfs2(root,-1,-1,0);
		int Q;scanf("%d",&Q);
		while(Q--){
			int a,b;scanf("%d%d",&a,&b);
			a=find(a);b=find(b);
		//	printf("belong[a]=%d,belong[b]=%d\n",belong[a],belong[b]);getchar();
			if(a==b){//在同一个连通块里
				printf("%d\n",edgeCnt);
				continue;
			}else{
				int tmp=0;
				a=find(a);b=find(b);
				while(a!=b){
					if(depth[a]<depth[b])swap(a,b);//a为深度大的那个

					int id=parID[a];
					if(!es[1][id].isCut){
						++tmp;
						es[1][id].isCut=es[1][id^1].isCut=1;
					}
					a=par[a];
				}
				edgeCnt-=tmp;
			}
			printf("%d\n",edgeCnt);
		}
		printf("\n");
	}
	return 0;
}
