#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=6007;
const int INF=1e9+7;
int a[MAXN];
int dp[MAXN][2];
struct edge{
	int to,next;
}es[MAXN*2];
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int dfs(int u,int status,int prev){
	if(dp[u][status]!=-INF)return dp[u][status];
	int res=0;
	int hasSon=0;
	if(status==1){//选择u
		res+=a[u];
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(v==prev)continue;
			hasSon=1;
			res+=dfs(v,0,u);
		}
	}else{//不选择u
		for(int i=head[u];~i;i=es[i].next){
			int v=es[i].to;
			if(v==prev)continue;
			hasSon=1;
			res+=max(dfs(v,0,u),dfs(v,1,u));
		}
	}
	if(!hasSon&&status==1)res=1;
	//printf("dp[%d][%d]=%d\n",u,status,res);
	return dp[u][status]=res;
}
int du[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		for(int i=1;i<=N;++i){
			dp[i][0]=dp[i][1]=-INF;
			du[i]=0;
		}
		init();
		for(int i=1;i<=N;++i){
			int x,y;scanf("%d%d",&x,&y);
			if(i==N)break;
			du[x]++;
			addEdge(x,y);
			addEdge(y,x);
		}
		int root=1;
		for(;du[root];++root);
		dfs(root,1,-1);
		//printf("--------------\n");
		dfs(root,0,-1);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
	return 0;
}
