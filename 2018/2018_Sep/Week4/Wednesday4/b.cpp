#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;

const int MAXN=27;
const int MAXM=1e5+7;
const int INF=1e9+7;
int MAX[MAXN][MAXM<<2],MIN[MAXN][MAXM<<2],SUM[MAXN][MAXM<<2];
int N,M,Q;
int add[MAXN][MAXM<<2],set[MAXN][MAXM<<2];

void init(){
	memset(MAX,0,sizeof(MAX));
	memset(MIN,0,sizeof(MIN));
	memset(SUM,0,sizeof(SUM));
	memset(add,0,sizeof(add));
	memset(set,-1,sizeof(set));
}

void PushUp(int k,int rt){
	MAX[k][rt]=max(MAX[k][rt<<1],MAX[k][rt<<1|1]);
	MIN[k][rt]=min(MIN[k][rt<<1],MIN[k][rt<<1|1]);
	SUM[k][rt]=SUM[k][rt<<1]+SUM[k][rt<<1|1];
}

void PushDown(int k,int l,int r,int rt){
	int len=r-l+1;
	if(set[k][rt]!=-1){
		add[k][rt]=0;
		set[k][rt<<1]=set[k][rt<<1|1]=set[k][rt];
		MAX[k][rt<<1]=MAX[k][rt<<1|1]=set[k][rt];
		MIN[k][rt<<1]=MIN[k][rt<<1|1]=set[k][rt];
		SUM[k][rt<<1]=(len-len/2)*set[k][rt];
		SUM[k][rt<<1|1]=len/2*set[k][rt];
		set[k][rt]=-1;
	}

	if(add[k][rt]){
		add[k][rt<<1]+=add[k][rt];add[k][rt<<1|1]+=add[k][rt];
		MAX[k][rt<<1]+=add[k][rt];MAX[k][rt<<1|1]+=add[k][rt];
		MIN[k][rt<<1]+=add[k][rt];MIN[k][rt<<1|1]+=add[k][rt];
		SUM[k][rt<<1]+=(len-len/2)*add[k][rt];
		SUM[k][rt<<1|1]+=len/2*add[k][rt];
		add[k][rt]=0;
	}
}

void update(int k,int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		MAX[k][rt]+=val;
		MIN[k][rt]+=val;
		SUM[k][rt]+=val*(r-l+1);
		add[k][rt]+=val;
		return;
	}
	PushDown(k,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)update(k,L,R,val,lson);
	if(R>m)update(k,L,R,val,rson);
	PushUp(k,rt);
}

void sett(int k,int L,int R,int val,int l,int r,int rt){
	if(l>=L&&r<=R){
		MAX[k][rt]=val;
		MIN[k][rt]=val;
		SUM[k][rt]=val*(r-l+1);
		add[k][rt]=0;
		set[k][rt]=val;
		return;
	}
	PushDown(k,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)sett(k,L,R,val,lson);
	if(R>m)sett(k,L,R,val,rson);
	PushUp(k,rt);
}

int MAXVAL,MINVAL,SUMVAL;
void query(int k,int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		MAXVAL=max(MAXVAL,MAX[k][rt]);
		MINVAL=min(MINVAL,MIN[k][rt]);
		SUMVAL+=SUM[k][rt];
		return;
	}
	PushDown(k,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)query(k,L,R,lson);
	if(R>m)query(k,L,R,rson);
	PushUp(k,rt);
}

int main(){
	while(~scanf("%d%d%d",&N,&M,&Q)){
		init();
		while(Q--){
			int q;scanf("%d",&q);
			if(q==1){
				int x1,y1,x2,y2,v;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int i=x1;i<=x2;++i)
					update(i,y1,y2,v,1,M,1);
			}else if(q==2){
				int x1,y1,x2,y2,v;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
				for(int i=x1;i<=x2;++i)
					sett(i,y1,y2,v,1,M,1);
			}else if(q==3){
				MINVAL=INF,MAXVAL=-INF,SUMVAL=0;
				int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				for(int i=x1;i<=x2;++i)
					query(i,y1,y2,1,M,1);
				printf("%d %d %d\n",SUMVAL,MINVAL,MAXVAL);
			}
		}
	}
	return 0;
}
