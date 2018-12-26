#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

int N,M;
const int MAXN=2e5+7;
const int INF=1e9+7;
int a[MAXN<<2];
void PushUp(int rt){
	a[rt]=max(a[rt<<1],a[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&a[rt]);
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return a[rt];
	int res=0;
	int m=(l+r)/2;
	if(L<=m)res=max(res,query(L,R,lson));
	if(R>m)res=max(res,query(L,R,rson));
	return res;
}

void update(int p,int x,int l,int r,int rt){
	if(l==r){
		a[rt]=x;
		return;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
	PushUp(rt);
}

int main(){
	while(~scanf("%d%d",&N,&M)){
		build(1,N,1);	
		int l,r;
		char s[3];scanf("%s%d%d",s,&l,&r);
		if(s[0]=='Q')printf("%d\n",query(l,r,1,N,1));
		else update(l,r,1,N,1);
	}
	return 0;
}
