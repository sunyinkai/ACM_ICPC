#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

using namespace std;

const int MAXN=1e5+7;
const int INF=1e9+7;
int a[MAXN];
char s[MAXN];
int cnt[MAXN<<2];
void PushUp(int rt){
	cnt[rt]=min(cnt[rt<<1],cnt[rt<<1|1]);
}

void build(int l,int r,int rt){
	if(l==r){
		cnt[rt]=0;
		return;
	}
	int m=(l+r)/2;
	build(lson);
	build(rson);
}
void update(int p,int x,int l,int r,int rt){
	if(l==r){
		cnt[rt]+=x;
		return;
	}
	int m=(l+r)/2;
	if(p<=m)update(p,x,lson);
	else update(p,x,rson);
	PushUp(rt);
}
int  query(int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		return cnt[rt];
	}
	int m=(l+r)/2;
	int ans=INF;
	if(L<=m)ans=min(ans,query(L,R,lson));
	if(R>m)ans=min(ans,query(L,R,rson));
	return ans;
}

int main(){
	freopen("out.txt","r",stdin);
	int N,M;scanf("%d%d",&N,&M);
	int val=1;
	for(int i=1;i<=M;++i){
		int x;scanf("%d",&x);
		update(x,1,1,N,1);
		if(query(1,N,1,N,1)==val){
			++val;
			s[i]='1';
		}else s[i]='0';
		s[i+1]='\0';
	}
	printf("%s\n",s+1);
	return 0;
}
