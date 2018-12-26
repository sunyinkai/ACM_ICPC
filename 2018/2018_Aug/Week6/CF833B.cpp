#include<cstdio>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#include<algorithm>
using namespace std;

const int MAXN=4e4+7;
int a[MAXN];
int pre[MAXN],dp[57][MAXN];
int mx[MAXN<<2],col[MAXN<<2];

void PushUp(int rt){
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}

void PushDown(int rt){
	if(col[rt]){
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		mx[rt<<1]+=col[rt];
		mx[rt<<1|1]+=col[rt];
		col[rt]=0;
	}
}

void build(int k,int l,int r,int rt){
	col[rt]=0;
	if(l==r){
		mx[rt]=dp[k][l-1];
		return ;
	}
	int m=(l+r)/2;
	build(k,lson);
	build(k,rson);
	PushUp(rt);
}

void update(int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		col[rt]+=val;
		mx[rt]+=val;
		return;
	}
	PushDown(rt);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R)return mx[rt];
	PushDown(rt);
	int m=(l+r)/2;
	int res=0;
	if(L<=m)res=max(res,query(L,R,lson));
	if(R>m)res=max(res,query(L,R,rson));
	PushUp(rt);
	return res;
}

int main(){
	int N,K;scanf("%d%d",&N,&K);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	for(int k=1;k<=K;++k){
		build(k-1,1,N,1);
		memset(pre,0,sizeof(pre));

		for(int i=1;i<=N;++i){
			int l=pre[a[i]]+1,r=i;
			update(l,r,1,1,N,1);
			dp[k][i]=query(1,i,1,N,1);
		//	printf("dp[%d][%d]=%d\n",k,i,dp[k][i]);
			pre[a[i]]=i;
		}
	}
	printf("%d\n",dp[K][N]);
	return 0;
}
