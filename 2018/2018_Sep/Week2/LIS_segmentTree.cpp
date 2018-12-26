#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN=1e5+7;
int a[MAXN<<2];
//线段树维护LIS
void PushUp(int rt){
	a[rt]=max(a[rt<<1],a[rt<<1|1]);
}

void update(int p,int x,int l,int r,int rt){
	if(l==r){
		a[rt]=x;
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
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

int main(){
	int N;
	while(~scanf("%d",&N)){
		//我们假设a_i均小于1e5,如果大于1e5可以离散化
		memset(a,0,sizeof(a));
		int res=0;
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			int val=query(1,x,1,MAXN-1,1)+1;
			res=max(res,val);
			update(x,val,1,MAXN-1,1);
		}
		printf("%d\n",res);
	}
	return 0;
}
