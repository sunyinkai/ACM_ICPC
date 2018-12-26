#include<cstdio>
#include<cstring>
#include<set>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=1e5+7;
int sum[MAXN<<2],a[MAXN];
int col[MAXN<<2];
void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int len){
	if(col[rt]){
		if(col[rt]&1){
			sum[rt<<1]=(len-len/2)-sum[rt<<1];
			sum[rt<<1|1]=len/2-sum[rt<<1|1];
		}
		col[rt<<1]=(col[rt<<1]+col[rt])%2;
		col[rt<<1|1]=(col[rt<<1|1]+col[rt])%2;
		col[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&a[l]);
		sum[rt]=a[l]&1;
		return ;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		if(val&1){
			sum[rt]=(r-l+1)-sum[rt];
			col[rt]=(col[rt]+val)%2;
		}
		return;
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(L,R,val,lson);
	if(R>m)update(L,R,val,rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		return sum[rt];
	}
	PushDown(rt,r-l+1);
	int m=(l+r)/2;
	int res=0;
	if(L<=m)res+=query(L,R,lson);
	if(R>m)res+=query(L,R,rson);
	return res;
}

set<int>st;
int q[MAXN],top;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		st.clear();
		int N,Q;scanf("%d%d",&N,&Q);
		build(1,N,1);
		for(int i=1;i<=N;++i){
			if(a[i]<9)st.insert(i);
		}//st维护小于9的数的下标

		while(Q--){
			int x;scanf("%d",&x);
			if(x==0){
				int L,R,val;scanf("%d%d%d",&L,&R,&val);
				top=0;
				for(auto it=st.lower_bound(L);it!=st.end();++it){
					int x=*it;
					if(x<=R){
						update(x,x,val,1,N,1);
						printf("l=%d,r=%d\n",x,x);
						q[top++]=x;
						a[x]+=val;
					}else break;
				}
				//q数组，下标
				for(int i=0;i<top;++i){
					if(a[q[i]]>=9)st.erase(q[i]);
					if(i==0){//第一个
						if(a[q[i]]!=L){
							int l=L,r=q[0]-1;
							printf("l=%d,r=%d\n",l,r);
							update(l,r,val,1,N,1);
						}
					}else{
						int l=q[i]-1,r=q[i-1]+1;
						if(l<=r){
							printf("l=%d,r=%d\n",l,r);
							update(l,r,val,1,N,1);
						}
					}
					if(i==top-1){
						if(a[q[i]]!=R){
							int l=q[i]+1,r=R;
							printf("l=%d,r=%d\n",l,r);
							if(l<=r){
								update(l,r,val,1,N,1);
							}
						}
					}
				}
				
			}else{
				int l,r;scanf("%d%d",&l,&r);
				int all=query(l,r,1,N,1);
				printf("all=%d\n",all);
			}
		}
	}
	return 0;
}
