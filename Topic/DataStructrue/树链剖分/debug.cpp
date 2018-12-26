#include<cstdio>
#include<cstring>
#define swap(a,b) (a^=b^=a^=b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const long long MAXV=1e5+7;
const long long MAXE=1e5+7;
struct edge{
	long long to,next;
}es[MAXE*2];
long long tot=0,head[MAXV];
long long N,M,root,MOD;
long long val[MAXV];
void init(){
	memset(head,-1,sizeof(head));
	tot=0;
}
void addEdge(long long a,long long b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
long long dep[MAXV],par[MAXV],siz[MAXV],son[MAXV];
void dfs1(long long u,long long pre,long long d){
	dep[u]=d;
	par[u]=pre;
	siz[u]=1;
	son[u]=-1;
	for(long long i=head[u];~i;i=es[i].next){
		long long v=es[i].to;
		if(v==par[u])continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if(son[u]==-1||siz[son[u]]<siz[v]){
			son[u]=v;
		}
	}
}
long long top[MAXV],p[MAXV],fp[MAXV],time=0;
void dfs2(long long u,long long sp){
	top[u]=sp;
	p[u]=++time;
	fp[time]=u;
	if(son[u]==-1)return;
	dfs2(son[u],sp);
	for(long long i=head[u];~i;i=es[i].next){
		long long v=es[i].to;
		if(v==son[u]||v==par[u])continue;
		dfs2(v,v);
	}
}

long long rt[MAXV<<2],a[MAXV<<2],col[MAXV<<2];
void PushUp(long long rt){
	a[rt]=(a[rt<<1]+a[rt<<1|1])%MOD;
}
void PushDown(long long rt,long long len){
	if(col[rt]){
		col[rt<<1]=(col[rt<<1]+col[rt])%MOD;
		col[rt<<1|1]=(col[rt<<1|1]+col[rt])%MOD;
		a[rt<<1]=(a[rt<<1]+col[rt]*(len-len/2))%MOD;
		a[rt<<1|1]=(a[rt<<1|1]+col[rt]*len/2)%MOD;
		col[rt]=0;
	}
}
void build(long long l,long long r,long long rt){
	if(l==r){
		a[rt]=val[fp[l]]%MOD;
		return ;
	}
	long long m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(long long L,long long R,long long x,long long l,long long r,long long rt){//区间修改
		if(l>=L&&r<=R){
			col[rt]=(col[rt]+x)%MOD;
			a[rt]=(a[rt]+(long long)x*(r-l+1))%MOD;
			return;
		}
		PushDown(rt,r-l+1);
		long long m=(l+r)/2;
		if(L<=m)update(L,R,x,lson);
		if(R>m)update(L,R,x,rson);
		PushUp(rt);
}
long long query(long long L,long long R,long long l,long long r,long long rt){//区间询问
	if(l>=L&&r<=R){
		return a[rt]%MOD;
	}
	PushDown(rt,r-l+1);
	long long m=(l+r)/2;
	long long sum=0;
	if(L<=m)sum=(sum+query(L,R,lson))%MOD;
	if(R>m)sum=(sum+query(L,R,rson))%MOD;
	return sum;
}
void modify(long long u,long long v,long long x){
	//prlong longf("top[u]=%lld,top[v]=%lld\n",top[u],top[v]);
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		update(p[top[u]],p[u],x,1,N,1);
		u=par[top[u]];
	}
	//if(u==v)return;,son[u]
	if(dep[u]>dep[v])swap(u,v);
	update(p[u],p[v],x,1,N,1);
}
long long ask(long long u,long long v){
	long long sum=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		sum=(sum+query(p[top[u]],p[u],1,N,1))%MOD;
		u=par[top[u]];
	}
	//if(u==v)return sum;
	if(dep[u]>dep[v])swap(u,v);
	sum=(sum+query(p[u],p[v],1,N,1))%MOD;
	return sum;
}
int main(){
	scanf("%lld%lld%lld%lld",&N,&M,&root,&MOD);
	for(long long i=1;i<=N;++i)scanf("%lld",&val[i]);
	init();
	for(long long i=1;i<N;++i){
		long long x,y;scanf("%lld%lld",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}//read
	dfs1(root,0,1);
	dfs2(root,root);
	build(1,N,1);
	for(long long i=0;i<M;++i){
		long long q;scanf("%lld",&q);
		if(q==1){
			long long x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			modify(x,y,z%MOD);
		}else if(q==2){
			long long x,y;scanf("%lld%lld",&x,&y);
			printf("%lld\n",ask(x,y)%MOD);
		}else if(q==3){//子树加上x
			long long x,z;scanf("%lld%lld",&x,&z);
			update(p[x],p[x]+siz[x]-1,z%MOD,1,N,1);
		}else{//询问子树
			long long x;scanf("%lld",&x);
			printf("%lld\n",query(p[x],p[x]+siz[x]-1,1,N,1)%MOD);
		}
	}
	return 0;
}
