#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int MAXN=1e5+7;
ll a[MAXN<<2],muti[MAXN<<2],add[MAXN<<2];
int N,M;ll mod;
void  PushUp(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void PushDown(int rt,int len){
	muti[rt<<1]=muti[rt<<1]*muti[rt]%mod;
	muti[rt<<1|1]=muti[rt<<1|1]*muti[rt]%mod;
	add[rt<<1]=add[rt<<1]*muti[rt]%mod;
	add[rt<<1|1]=add[rt<<1|1]*muti[rt]%mod;
	a[rt<<1]=a[rt<<1]*muti[rt]%mod;
	a[rt<<1|1]=a[rt<<1|1]*muti[rt]%mod;

	muti[rt]=1;
	add[rt<<1]=(add[rt<<1]+add[rt])%mod;
	add[rt<<1|1]=(add[rt<<1|1]+add[rt])%mod;
	a[rt<<1]=(a[rt<<1]+(len-len/2)*add[rt])%mod;
	a[rt<<1|1]=(a[rt<<1|1]+len/2*add[rt])%mod;
	add[rt]=0;

}
void build(int l,int r,int rt){
	add[rt]=0;muti[rt]=1;
	if(l==r){
		scanf("%lld",&a[rt]);
		a[rt]%=mod;
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int kind,int L,int R,long long val,int l,int r,int rt){
	if(l>=L&&r<=R){
		if(kind==1){//muti
			muti[rt]=muti[rt]*val%mod;
			add[rt]=add[rt]*val%mod;
			a[rt]=a[rt]*val%mod;
		}else{//add
			add[rt]=(add[rt]+val)%mod;
			a[rt]=(a[rt]+val*(r-l+1))%mod;
		}
		return ;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(kind,L,R,val,lson);
	if(R>m)update(kind,L,R,val,rson);
	PushUp(rt);
}
ll query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		return a[rt]%mod;
	}
	PushDown(rt,r-l+1);
	ll res=0;
	int m=(l+r)/2;
	if(L<=m)res=(res+query(L,R,lson))%mod;
	if(R>m)res=(res+query(L,R,rson))%mod;
	PushUp(rt);
	return res;
}
int main(){
	scanf("%d%d%lld",&N,&M,&mod);
	build(1,N,1);
	for(int i=0;i<M;++i){
		int q;scanf("%d",&q);
		if(q==1){
			int a,b;ll k;
			scanf("%d%d%lld",&a,&b,&k);
			update(1,a,b,k%mod,1,N,1);
		}else if(q==2){
			int a,b;ll k;
			scanf("%d%d%lld",&a,&b,&k);
			update(2,a,b,k%mod,1,N,1);
		}else{
			int L,R;scanf("%d%d",&L,&R);
			printf("%lld\n",query(L,R,1,N,1));
		}
	}
	return 0;
}
