#include<cstdio>
#include<cstring>
#define swap(a,b) (a^=b^=a^=b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXV=2e5+7;
const int MAXE=2e5+7;
struct edge{
	int to,next;
}es[MAXE*2];
int tot=0,head[MAXV];
int N,M,root,MOD;
int val[MAXV];
void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}
void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int dep[MAXV],par[MAXV],siz[MAXV],son[MAXV];
void dfs1(int u,int pre,int d){
	dep[u]=d;
	par[u]=pre;
	siz[u]=1;
	son[u]=-1;
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==par[u])continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if(son[u]==-1||siz[son[u]]<siz[v]){
			son[u]=v;
		}
	}
}
int top[MAXV],p[MAXV],fp[MAXV],time=0;
void dfs2(int u,int sp){
	top[u]=sp;
	p[u]=++time;
	fp[time]=u;
	if(son[u]==-1)return;
	dfs2(son[u],sp);
	for(int i=head[u];~i;i=es[i].next){
		int v=es[i].to;
		if(v==son[u]||v==par[u])continue;
		dfs2(v,v);
	}
}

int rt[MAXV<<2],a[MAXV<<2],col[MAXV<<2];
void PushUp(int rt){
	a[rt]=(a[rt<<1]+a[rt<<1|1])%MOD;
}
void PushDown(int rt,int len){
	if(col[rt]){
		col[rt<<1]=(col[rt<<1]+col[rt])%MOD;
		col[rt<<1|1]=(col[rt<<1|1]+col[rt])%MOD;
		a[rt<<1]=(a[rt<<1]+col[rt]*(len-len/2))%MOD;
		a[rt<<1|1]=(a[rt<<1|1]+col[rt]*len/2)%MOD;
		col[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		a[rt]=val[fp[l]]%MOD;
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int x,int l,int r,int rt){//区间修改
		if(l>=L&&r<=R){
			col[rt]=(col[rt]+x)%MOD;
			a[rt]=(a[rt]+(long long)x*(r-l+1))%MOD;
			return;
		}
		PushDown(rt,r-l+1);
		int m=(l+r)/2;
		if(L<=m)update(L,R,x,lson);
		if(R>m)update(L,R,x,rson);
		PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){//区间询问
	if(l>=L&&r<=R){
		return a[rt]%MOD;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	int sum=0;
	if(L<=m)sum=(sum+query(L,R,lson))%MOD;
	if(R>m)sum=(sum+query(L,R,rson))%MOD;
	return sum;
}
void modify(int u,int v,int x){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		update(p[top[u]],p[u],x,1,N,1);
		u=par[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	update(p[u],p[v],x,1,N,1);
}
int ask(int u,int v){
	int sum=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		sum=(sum+query(p[top[u]],p[u],1,N,1))%MOD;
		u=par[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	sum=(sum+query(p[u],p[v],1,N,1))%MOD;
	return sum%MOD;
}
int main(){
	scanf("%d%d%d%d",&N,&M,&root,&MOD);
	for(int i=1;i<=N;++i)scanf("%d",&val[i]);
	init();
	for(int i=1;i<N;++i){
		int x,y;scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}//read
	dfs1(root,0,1);
	dfs2(root,root);
	build(1,N,1);
	for(int i=0;i<M;++i){
		int q;scanf("%d",&q);
		if(q==1){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			modify(x,y,z%MOD);
		}else if(q==2){
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",ask(x,y)%MOD);
		}else if(q==3){//子树加上x
			int x,z;scanf("%d%d",&x,&z);
			update(p[x],p[x]+siz[x]-1,z%MOD,1,N,1);
		}else{//询问子树
			int x;scanf("%d",&x);
			printf("%d\n",query(p[x],p[x]+siz[x]-1,1,N,1)%MOD);
		}
	}
	return 0;
}
