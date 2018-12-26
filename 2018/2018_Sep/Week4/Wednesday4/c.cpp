#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int MAXN=5e4+7;
const int INF=1e9+7;
int a[MAXN<<2];
void PushUp(int rt){
	a[rt]=min(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		a[rt]=INF;
		if(l==1)a[rt]=0;
		return;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return a[rt];
	int res=INF;
	int m=(l+r)/2;
	if(L<=m)res=min(res,query(L,R,lson));
	if(R>m)res=min(res,query(L,R,rson));
	return res;
}
void update(int p,int x,int l,int r,int rt){
	if(l==r){
		a[rt]=min(a[rt],x);
		return;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
	PushUp(rt);
}
int main(){
	int T;scanf("%d",&T);
	int isok=0;
	while(T--){
		int N,M;scanf("%d%d",&N,&M);
		if(isok)printf("\n");
		isok=1;
		build(1,N,1);
		for(int i=0;i<M;++i){
			int l,r;scanf("%d%d",&l,&r);
			int val=query(l,r,1,N,1)+1;
			update(r,val,1,N,1);
		}
		printf("%d\n",query(N,N,1,N,1));
	}
	return 0;
}

