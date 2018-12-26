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
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int p,int x,int l,int r,int rt){
	if(l==r){
		a[rt]=min(a[rt],x);
		return ;
	} 
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
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

int main(){
	int T;scanf("%d",&T);
	int tag=0;
	while(T--){
		if(tag)printf("\n");
		tag=1;
		int N,M;scanf("%d%d",&N,&M);
		build(1,N,1);
		for(int i=0;i<M;++i){
			int x,y;scanf("%d%d",&x,&y);
			int val=query(x,y,1,N,1);
			update(y,val+1,1,N,1);
		}
		printf("%d\n",query(N,N,1,N,1));
	}
	return 0;
}
