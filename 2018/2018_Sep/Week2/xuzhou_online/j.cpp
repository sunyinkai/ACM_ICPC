#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN=507*507;
struct edgee{
	int from,to,cost;
	bool operator<(const edgee&other)const{
		return cost>other.cost;
	}
}ess[MAXN*2+7];

int tot=0;
void addEdgee(int a,int b,int c){
	ess[tot].from=a;ess[tot].to=b;ess[tot].cost=c;
	tot++;
}

int N,M,NN,MM;
void input(){
	scanf("%d%d",&NN,&MM);
	N=NN*NN;
	for(int i=0;i<NN;++i){
		for(int j=0;j<MM;++j){
			int no=i*MM+j+1;
			char d[2],r[2];
			int x,y;
			scanf("%s%d%s%d",d,&x,r,&y);
			if(d[0]=='D'){
			//	printf("%d - %d c:%d\n",no,(i+1)*MM+j+1,x);
				addEdgee(no,no+MM,x);
			}
			if(r[0]=='R'){
			//	printf("%d - %d c:%d\n",no,i*MM+j+1+1,y);
				addEdgee(no,no+1,y);
			}
		}
	}
}

int parr[MAXN];
int find(int i){
	return parr[i]==i?parr[i]:parr[i]=find(parr[i]);
}

int q[MAXN],top=0;//最大生成树可行边
void MST(){
	for(int i=1;i<=N;++i)parr[i]=i;
	sort(ess,ess+tot);
	for(int i=0;i<tot;++i){
		int u=ess[i].from,v=ess[i].to;
		int x=find(u),y=find(v);
		if(x!=y){
			parr[x]=y;
			q[top++]=i;
		}
	}
}

int head[MAXN];
int root;
struct edge{
	int to,next;
}es[MAXN*2];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int par[MAXN][21],depth[MAXN];
void dfs(int u,int pre,int dep){
	par[u][0]=pre;
	depth[u]=dep;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==pre)continue;
		dfs(v,u,dep+1); 
	}
}
void LCA_init(){
	for(int k=1;k<=20;++k){
		for(int i=1;i<=N;++i){
			int u=par[i][k-1];
			if(u!=-1){
				par[i][k]=par[u][k-1];
			}
		}
	}
}
int query(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	int len=depth[a]-depth[b];
	for(int i=0;(1<<i)<=len;++i)
		if(len&(1<<i))a=par[a][i];
	if(a!=b){
		for(int i=20;i>=0;--i){
			if(par[a][i]!=par[b][i])a=par[a][i],b=par[b][i];
		}
		a=par[a][0];
	}
	return a;
}

void solve(){
	init();
	for(int i=0;i<top;++i){
		int u=ess[q[i]].from,v=ess[q[i]].to;
		addEdge(u,v);
		addEdge(v,u);
	}
	memset(par,-1,sizeof(par));
	root=1;
	dfs(root,-1,0);
	LCA_init();
	int Q;scanf("%d",&Q);
	while(Q--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int xx=(a-1)*MM+b,yy=(c-1)*MM+d;
		int x=query(xx,yy);
		printf("%d\n",depth[xx]+depth[yy]-depth[x]*2);
	}
}

int main(){
	input();
	MST();
	solve();
	return 0;
}
