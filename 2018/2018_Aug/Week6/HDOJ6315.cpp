#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int MAXN=1e5+7;
const int INF=1e9+7;
int x[MAXN],col[MAXN<<2];
int mx[MAXN<<2],a[MAXN<<2];
void PushUp(int rt){
	mx[rt]=min(mx[rt<<1],mx[rt<<1|1]);
	a[rt]=a[rt<<1]+a[rt<<1|1];
}

void PushDown(int rt,int len){
	col[rt<<1]+=col[rt];
	col[rt<<1|1]+=col[rt];
	mx[rt<<1]+=col[rt];
	mx[rt<<1|1]+=col[rt];
	col[rt]=0;
}

void build(int l,int r,int rt){
	col[rt]=a[rt]=0;
	if(l==r){
		mx[rt]=x[l];
		return;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		mx[rt]+=val;
		col[rt]+=val;
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	PushUp(rt);
}

int query_min(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return mx[rt];
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	int res=INF;
	if(L<=m)res=min(res,query_min(L,R,lson));
	if(R>m)res=min(res,query_min(L,R,rson));
	PushUp(rt);
	return res;
}

void get_pos(int val,int l,int r,int rt){
	//printf("val=%d,l=%d,r=%d\n",val,l,r);
	//printf("mx[rt<<1]=%d,mx[rt<<1|1]=%d\n",mx[rt<<1],mx[rt<<1|1]);
	if(l==r){
		mx[rt]=x[l];
		a[rt]++;
		return ;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(mx[rt<<1]==val)get_pos(val,lson);
	else if(mx[rt<<1|1]==val)get_pos(val,rson);
	PushUp(rt);
}

int query_sum(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return a[rt];
	PushDown(rt,r-l+1);
	int res=0;
	int m=(l+r)/2;
	if(L<=m)res+=query_sum(L,R,lson);
	if(R>m)res+=query_sum(L,R,rson);
	PushUp(rt);
	return res;
}


int main(){
	int N,Q;
	while(~scanf("%d%d",&N,&Q)){
		for(int i=1;i<=N;++i)scanf("%d",&x[i]);
		build(1,N,1);
		while(Q--){
			char s[10];
			scanf("%s",s);
			while(query_min(1,N,1,N,1)==0){
				get_pos(0,1,N,1);
			}
			if(s[0]=='a'){
				int l,r;scanf("%d%d",&l,&r);
				update(l,r,-1,1,N,1);
			}else{
				int l,r;scanf("%d%d",&l,&r);
				printf("%d\n",query_sum(l,r,1,N,1));
			}
		}
	}
	return 0;
}
