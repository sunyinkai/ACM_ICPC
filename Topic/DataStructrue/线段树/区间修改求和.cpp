#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=1e5+7;
long long  a[MAXN<<2];
int lazy[MAXN<<2];
int N,M;
void pushUp(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void pushDown(int rt,int len){
	if(lazy[rt]){
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];

		a[rt<<1]+=(len-len/2)*lazy[rt];
		a[rt<<1|1]+=len/2*lazy[rt];
		lazy[rt]=0;
	}
}
void build(int l,int r,int rt){
	lazy[rt]=0;
	if(l==r){
		scanf("%lld",&a[rt]);
		return;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	pushUp(rt);
}
long long query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		return a[rt];
	}
	pushDown(rt,r-l+1);
	int m=(l+r)/2;
	long long res=0;
	if(L<=m)res+=query(L,R,lson);
	if(R>m)res+=query(L,R,rson);
	return res;
}
void update(int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		a[rt]+=(long long)val*(r-l+1);
		lazy[rt]+=val;
		return;
	}
	pushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	pushUp(rt);
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		build(1,N,1);
		char s[2];scanf("%s",s);
		if(s[0]=='Q'){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r,1,N,1));
		}else{
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,1,N,1);
		}
	}
	return 0;
}
