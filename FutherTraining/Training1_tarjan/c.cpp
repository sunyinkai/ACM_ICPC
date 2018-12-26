#include<cstdio>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int MAXV=2e5+7,MAXE=2e5+7;
unordered_map<long long ,int>mp;
struct edge{
	int to,next,from;
	bool operator <(const edge & other)const{
		return from<other.from||(from==other.from &&to <other.to);
	}
}es[2*MAXE],ans[2*MAXE];
int tot,head[MAXV];
int top;
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int dfn[MAXV],low[MAXV],dfs_clock;
void dfs(int u,int par){
	dfn[u]=low[u]=++dfs_clock;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==par)continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				int x=u,y=v;//不能改变u,v
				if(x>y)swap(x,y);
				if(mp[(long long)x*MAXE+y]>=2)continue;
				ans[top].from=x;
				ans[top++].to=y;
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	int V;
	while(~scanf("%d",&V)){
		init();
		mp.clear();
		for(int i=0;i<V;++i){
			int num;scanf("%d ",&num);
			int cnt=0;
			scanf("(%d)",&cnt);//()
	//		printf("cnt=%d\n",cnt);
			for(int j=0;j<cnt;++j){
				int x;scanf("%d",&x);
				if(num>x){
					addEdge(x,num);
					addEdge(num,x);
					mp[(long long)x*MAXE+num]++;
					mp[(long long)num*MAXE+x]++;
				}
			}
		}
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		dfs_clock=0;
		top=0;
		for(int i=0;i<V;++i){
			if(!dfn[i])dfs(i,-1);
		}

		sort(ans,ans+top);
		printf("%d critical links\n",top);
		for(int i=0;i<top;++i){
			printf("%d - %d\n",ans[i].from,ans[i].to);
		}
		printf("\n");
	}
	return 0;
}
