#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=2e5+7;
const long long mod=1e9+7;
int k[MAXN<<2],b[MAXN<<2];
//操作1:将第i个函数修改为kx+b
//操作2:询问f_r(...f_l(x))的值
void PushUp(int rt){
	k[rt]=k[rt<<1]*k[rt<<1|1]%mod;
	b[rt]=(k[rt<<1|1]*b[rt<<1]+b[rt<<1|1])%mod;
}

void build(int l,int r,int rt){
	if(l==r){
		scanf("%d%d",&k[rt],&b[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
void query(int L,int R,int &val,int l,int r,int rt){
	if(l>=L&&r<=R){
		val=val*k[rt]+b[rt];
		return;
	}
	int m=(l+r)/2;
	if(L<=m)query(L,R,val,lson);
	if(R>m)query(L,R,val,rson);
}

void update(int pos,int K,int B,int l,int r,int rt){
	if(l==r){
		k[rt]=K;
		b[rt]=B;
		return;
	}
	int m=(l+r)/2;
	if(pos<=m)update(pos,K,B,lson);
	else update(pos,K,B,rson);
	PushUp(rt);
}

int main(){
	int N,M;scanf("%d%d",&N,&M);
	build(1,N,1);
	for(int i=0;i<M;++i){
		char s[3];scanf("%s",s);
		if(s[0]=='Q'){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			query(l,r,x,1,N,1);
			printf("%d\n",x);
		}else{
			int id,K,B;scanf("%d%d%d",&id,&K,&B);
			update(id,K,B,1,N,1);
		}
	}
	return 0;
}
