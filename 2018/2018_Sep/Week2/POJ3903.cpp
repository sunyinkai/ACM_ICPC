#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
const int MAXN=1e5+7;
long long x[MAXN],a[MAXN<<2],b[MAXN];
void PushUp(int rt){
	a[rt]=max(a[rt<<1],a[rt<<1|1]);
}
long long query(int L,int R,int l,int r,int rt){
	if(L==0||R==0)return 0;
	if(l>=L&&r<=R)return a[rt];
	long long res=0;
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
	int N;
	int T;scanf("%d",&T);
	while(T--&&scanf("%d",&N)){
	//	map<long long,int>mp;
		for(int i=0;i<=4*N;++i)a[i]=0;
		for(int i=0;i<N;++i)scanf("%lld",&b[i]),x[i]=b[i];
	//	sort(x,x+N);
	//	int tot=unique(x,x+N)-x;
	//	for(int i=0;i<tot;++i)mp[x[i]]=i+1;
		int res=0;
		for(int i=0;i<N;++i){
		//	int t=mp[b[i]];
			int t=b[i];
			int val=query(1,t-1,1,N,1);
			res=max(res,val+1);
			update(t,val+1,1,N,1);
		}
		printf("%d\n",res);
	}
	return 0;
}
