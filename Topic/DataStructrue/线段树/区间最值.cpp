#include<cstdio>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=3e5+7;
int a[MAXN<<2];
int read(){
	char ch;
	int res=0;
	while((ch=getchar())&&ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
	}
	return res;
}
void pushUp(int rt){
	a[rt]=max(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		a[rt]=read();
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushUp(rt);
}
void update(int p,int x,int l,int r,int rt){
	if(l==r){
		a[rt]=x;
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
	pushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return a[rt];
	int m=(l+r)>>1;
	int res=0;
	if(L<=m)res=max(res,query(L,R,lson));
	if(R>m)res=max(res,query(L,R,rson));
	return res;
}
int main(){
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF){
		getchar();
		build(1,N,1);
		for(int i=0;i<M;++i){
			char op;scanf("%c",&op);
			getchar();
			if(op=='Q'){
				int l=read(),r=read();
				printf("%d\n",query(l,r,1,N,1));
			}else{
				int p=read(),x=read();
				update(p,x,1,N,1);
			}
		}
	}
	return 0;
}

