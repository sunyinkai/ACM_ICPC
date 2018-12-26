#include<cstdio>
#include<cstring>
#define lson  l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=1e5+7;
int a[MAXN<<2],lazy[MAXN<<2];
int N,M;
void PushUp(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void PushDown(int rt,int len){
	if(lazy[rt]){
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
		a[rt<<1]=(len-len/2)*lazy[rt];
		a[rt<<1|1]=len/2*lazy[rt];
		lazy[rt]=0;
	}
}
void update(int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		lazy[rt]=val;
		a[rt]=val*(r-l+1);
		return ;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	PushUp(rt);
}
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%d%d",&N,&M);
		memset(lazy,0,sizeof(lazy));
		memset(a,0,sizeof(a));
		update(1,N,1,1,N,1);
		while(M--){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			update(x,y,z,1,N,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",test,a[1]);
	}
	return 0;
}
