#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
//线段树上的分治
const int MAXN=5e5+7;
int a[MAXN<<2],pre[MAXN<<2],suf[MAXN<<2],res[MAXN<<2];
int N,M;
void PushUp(int rt){
	pre[rt]=pre[rt<<1];
	suf[rt]=suf[rt<<1|1];
	if(pre[rt<<1]==res[rt<<1])pre[rt]+=pre[rt<<1|1];//跨区间
	if(suf[rt<<1|1]==res[rt<<1|1])suf[rt<<1|1]+=suf[rt<<1];
	
	res[rt]=max(res[rt<<1],res[rt<<1|1]);
	res[rt]=max(res[rt],suf[rt<<1]+pre[rt<<1|1]);
}

void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&a[rt]);
		res[rt]=a[rt];
		if(a[rt]>=0)pre[rt]=suf[rt]=a[rt];
		else pre[rt]=suf[rt]=0;
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
int Query(int L,int R,int l,int r,int rt){
	if(l==L&&r==R){
		return res[rt];
	}
	int m=(l+r)/2;
	int ans=0;
	if(L<=m)ans
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		build(1,N,1);
		for(int i=0;i<M;++i){
			int l,r;scanf("%d%d",&l,&r);
		}
	}
	return 0;
}
