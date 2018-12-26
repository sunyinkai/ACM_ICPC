#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;
const int MAXN=1e5+7;
struct node{
	int x,y,val;
	bool operator<(const node&other)const{
		return x<other.x||(x==other.x&&y>other.y);//x相等时,y从大到小,不用考虑同一行
	}
}no[MAXN];
int q[MAXN*2];
map<int,int>mp;
int a[MAXN<<3];
int dp[MAXN];
void build(int l,int r,int rt){
	a[rt]=0;
	if(l==r)return ;
	int m=(l+r)/2;
	build(lson);
	build(rson);
}

void PushUp(int rt){ a[rt]=max(a[rt<<1],a[rt<<1|1]); }
/*void print(int l,int r,int rt){
	printf("l=%d,r=%d,a[%d]=%d\n",l,r,rt,a[rt]);
	if(l==r)return;
	int m=(l+r)/2;
	print(lson);
	print(rson);
}*/
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
		return ;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
	PushUp(rt);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		mp.clear();
		no[0].x=0,no[0].y=0,no[0].val=0;
		no[N+1].x=1e9,no[N+1].y=1e9,no[N+1].val=0;

		int top=0;
		q[top++]=0;
		for(int i=1;i<=N;++i){
			scanf("%d%d%d",&no[i].x,&no[i].y,&no[i].val);
			q[top++]=no[i].x,q[top++]=no[i].y;
		}

		q[top++]=1e9;
		sort(q,q+top);
		top=unique(q,q+top)-q;
		for(int i=0;i<top;++i){
			mp[q[i]]=i+1;
		//	printf("mp[%d]=%d\n",q[i],mp[q[i]]);
		}

		build(1,top,1);
		sort(no,no+N+2);

		for(int i=1;i<=N+1;++i){
			int y=mp[no[i].y];
			dp[i]=query(1,y-1,1,top,1)+no[i].val;//询问[1,y]最大值
			update(y,dp[i],1,top,1);//update
			//print(1,top,1);
	//		printf("update:%d->%d\n",y,dp[i]);
		}
		printf("%d\n",dp[N+1]);
	}
	return 0;
}

