//区间修改,区间询问
#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=1e5+7;
long long a[MAXN<<2],col[MAXN<<2];
void PushUp(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void PushDown(int rt,long long len){
	if(col[rt]){
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		a[rt<<1]+=(len-len/2)*col[rt];
		a[rt<<1|1]+=(len/2)*col[rt];
		col[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%lld",&a[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,long long val,int l,int r,int rt){
	if(l>=L&&r<=R){
		a[rt]+=(r-l+1)*val;
		col[rt]+=val;
		return ;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	PushUp(rt);
}
long long query(int L,int R,int l,int r,int rt ){
	if(l>=L&&r<=R){
		return a[rt];
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	long long sum=0;
	if(L<=m)sum+=query(L,R,lson);
	if(R>m)sum+=query(L,R,rson);
	PushUp(rt);
	return sum;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	build(1,N,1);
	for(int i=0;i<M;++i){
		int q;scanf("%d",&q);
		if(q==1){//add
			int a,b;long long c;
			scanf("%d%d%lld",&a,&b,&c);
			update(a,b,c,1,N,1);
		}else{
			int a,b;scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b,1,N,1));
		}
	}
	return 0;
}
