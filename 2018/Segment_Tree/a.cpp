#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+7;

int a[MAXN<<2],x[MAXN],col[MAXN<<2];
int PushUp(int rt){
	a[rt]=min(a[rt<<1],a[rt<<1|1]);
}
void PushDown(int rt){
	if(col[rt]){
		col[rt<<1]=col[rt<<1|1]=col[rt];
		a[rt<<1]+=col[rt];
		a[rt<<1|1]+=col[rt];
		col[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&a[rt]);
		x[l]=a[rt];
		return ;
	}
	int m=(l+r)/2;
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	col[rt]=0;
	if(l>=L&&r<=R){
		return a[rt];
	}
	int m=(l+r)/2;
	int res=INF;
	if(L<=m)res=min(res,query(L,R,lson));
	if(R>m)res=min(res,query(L,R,rson));
	return res;
}

void add(int L,int R,int l,int r,int rt){//区间增加
	if(l>=L&&r<=R){
		col[rt]+=1;
		return ;
	}
	PushDown(rt);
	int m=(l+r)/2;
	if(L<=m)add(L,R,lson);
	if(R>m)add(L,R,rson);
	PushUp(rt);
}

int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)){
		build(1,N,1);
		for(int i=0;i<M;++i){
			int l,r;
			char s[10];
			scanf("%s%d%d",s,&l,&r);
			if(s[0]=='a'){
				add(l,r,1,N,1);
			}else{
				while(query(l,r,1,N,1)==0){
					update()
				}
			}
		}
	}
	return 0;
}
