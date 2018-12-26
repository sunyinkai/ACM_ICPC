#include<cstdio>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=1e5+7;
long long a[MAXN<<2],muti[MAXN<<2],add[MAXN<<2];
long long N,P;

void PushDown(int l,int r,int rt);
int query(int L,int R,int l,int r,int rt);
void PushUp(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void PushDown(int l,int r,int rt){
	muti[rt<<1]=muti[rt<<1]*muti[rt]%P;//==0?
	muti[rt<<1|1]=muti[rt<<1|1]*muti[rt]%P;
	int m=(l+r)/2;
	a[rt<<1]=a[rt<<1]%P*muti[rt]%P;
	a[rt<<1|1]=a[rt<<1|1]%P*muti[rt]%P;
	muti[rt]=1;

	int len=r-l+1;
	add[rt<<1]+=add[rt];
	add[rt<<1|1]+=add[rt];
	a[rt<<1]=(a[rt<<1]+add[rt]*(len-len/2))%P;
	a[rt<<1|1]=(a[rt<<1|1]+add[rt]*len/2)%P;
	add[rt]=0;
}



void build(int l,int r,int rt){
	add[rt]=0;
	muti[rt]=1;
	if(l==r){
		scanf("%lld",&a[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		return a[rt]%P;
	}
	PushDown(l,r,rt);
	int m=(l+r)/2;
	int sum=0;
	if(L<=m)sum=(sum+query(L,R,lson))%P;
	if(R>m)sum=(sum+query(L,R,rson))%P;
	return sum;
}

void update(int kind,int L,int R,int C,int l,int r,int rt){
	if(l>=L&&r<=R){
		if(kind==1){
			 a[rt]=a[rt]*C;
			 muti[rt]*=C;
		}else{
			a[rt]=(a[rt]+(r-l+1)*C)%P;
			add[rt]=(add[rt]+C)%P;
		} 
		return ;
	}
	int m=(l+r)/2;
	if(L<=m)update(kind,L,R,C,lson);
	if(R>m)update(kind,L,R,C,rson);
	PushUp(rt);
}
int main(){
	scanf("%lld%lld",&N,&P);
	build(1,N,1);
	int Q;scanf("%d",&Q);
	while(Q--){
		int op;scanf("%d",&op);
		if(op==1){
			int L,R,C;scanf("%d%d%d",&L,&R,&C);
			update(1,L,R,C,1,N,1);
		}else if(op==2){
			int L,R,C;scanf("%d%d%d",&L,&R,&C);
			update(2,L,R,C,1,N,1);
		}else{
			int L,R;scanf("%d%d",&L,&R);
			printf("%lld\n",query(L,R,1,N,1)%P);
		}
	}
	return 0;
}
