#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
//线段树单点修改，区间询问
const int MAXN=5e4+7;
const int INF=1e9+7;
int a[MAXN],N;
map<int,int>mp;
int x[MAXN<<2];
void discrete(int N){
	sort(a,a+N);
	N=unique(a,a+N)-a;
	for(int i=0;i<N;++i){
		mp[a[i]]=i+1;
	}
}

void pushUp(int rt){
	x[rt]=min(x[rt<<1],x[rt<<1|1]);
}

void build(int l,int r,int rt){
	if(l==r){
		x[rt]=INF;
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	pushUp(rt);
}

void update(int p,int val,int l,int r,int rt){
	if(l==r){
		x[rt]=min(x[rt],val);
		return;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,val,lson);
	else update(p,val,rson);
	pushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return x[rt];
	int ans=INF;
	int m=(l+r)/2;
	if(L<=m)ans=min(ans,query(L,R,lson));
	if(R>m)ans=min(ans,query(L,R,rson));
	return ans;
}

int main(){
	scanf("%d",&N);
	int t[MAXN];
	for(int i=0;i<N;++i)scanf("%d",&a[i]),t[i]=a[i];
	discrete(N);

	build(1,N,1);
	int ans=0;
	for(int i=0;i<N;++i){
		update(mp[t[i]],i+1,1,N,1);
		ans=max(ans,(i+1)-query(1,mp[t[i]],1,N,1));
	}
	printf("%d\n",ans);
	return 0;
}
