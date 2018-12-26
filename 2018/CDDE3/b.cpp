#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

const int MAXN=1e6+7;
const int MAXM=1e6+7;
struct node{
	int x,y;
	int col;
	bool operator<(const node&other)const{
		return x<other.x||(x==other.x&&y<other.y);
	}
}no[MAXN];
map<node,int>mp;
vector<int>row[MAXN],col[MAXN];

struct edge{
	int from,to,next;
}es[MAXM];
int head[MAXM],tot;

void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].from=a;
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int dfs_clock=0,dfn[MAXM],low[MAXM];
int scc,top,par[MAXM],inStack[MAXM],q[MAXM];
void dfs(int u,int pre){
	dfn[u]=low[u]=++dfs_clock;
	q[top++]=u;
	inStack[u]=1;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
		}else if(inStack[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++scc;
		for(;;){
			int no=q[--top];
	//		printf("%d ",no);
			inStack[no]=0;
			par[no]=scc;
			if(no==u)break;
		}
	//	printf("\n");
	}
}
int main(){
	int N;scanf("%d",&N);
	init();
	for(int i=1;i<=N;++i){
		scanf("%d%d",&no[i].x,&no[i].y);
		mp[no[i]]=i;

		row[no[i].x].push_back(i);//第x行有哪些节点的编号
		col[no[i].y].push_back(i);
	}
	for(int i=1;i<MAXN;++i){
		int len=row[i].size();
		for(int j=0;j+1<len;j+=2){
			int x=row[i][j],y=row[i][j+1];
			x=mp[no[x]];y=mp[no[y]];
		//	printf("x=%d,y=%d\n",x,y);
		//	printf("x=%d,y+N=%d\n",x,y+N);
		//	printf("y=%d,x+N=%d\n",y,x+N);
			addEdge(x,y+N);
			addEdge(y,x+N);
			addEdge(x+N,y);addEdge(y+N,x);
		}
	}

	for(int i=1;i<MAXN;++i){
		int len=col[i].size();
		for(int j=0;j+1<len;j+=2){
			int x=col[i][j],y=col[i][j+1];
			x=mp[no[x]];y=mp[no[y]];
			//printf("x=%d,y=%d\n",x,y);
			//printf("x=%d,y+N=%d\n",x,y+N);
			//printf("y=%d,x+N=%d\n",y,x+N);
			addEdge(x,y+N);
			addEdge(y,x+N);
			addEdge(x+N,y);addEdge(y+N,x);
		}
	}
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(inStack,0,sizeof(inStack));
	scc=0,top=0;
	for(int i=1;i<=2*N;++i)
		if(!dfn[i])dfs(i,-1);

	for(int i=1;i<=N;++i){
		if(par[i]>par[i+N]){
			printf("r");
		}else{
			printf("b");
		}
	}
	return 0;
}
