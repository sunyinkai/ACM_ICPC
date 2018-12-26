#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=21,MAXM=1e6+7;
const int INF=1e9+7;

int sum[MAXN][MAXM<<2],MIN[MAXN][MAXM<<2],MAX[MAXN][MAXM<<2];
int set[MAXN][MAXM<<2],add[MAXN][MAXM<<2];


void PushUp(int row,int rt){
	sum[row][rt]=sum[row][rt<<1]+sum[row][rt<<1|1];
	MAX[row][rt]=max(MAX[row][rt<<1],MAX[row][rt<<1|1]);
	MIN[row][rt]=min(MIN[row][rt<<1],MIN[row][rt<<1|1]);
}

void PushDown(int row,int l,int r,int rt){
	int len=r-l+1;
	if(set[row][rt]!=-1){//先set再add
		sum[row][rt<<1]=(len-len/2)*set[row][rt];
		sum[row][rt<<1|1]=len/2*set[row][rt];
		MAX[row][rt<<1]=MAX[row][rt<<1|1]=set[row][rt];
		MIN[row][rt<<1]=MIN[row][rt<<1|1]=set[row][rt];

		add[row][rt<<1]=add[row][rt<<1|1]=0;
		set[row][rt<<1]=set[row][rt<<1|1]=set[row][rt];
		set[row][rt]=-1;
	}
	if(add[row][rt]){
		sum[row][rt<<1]+=(len-len/2)*add[row][rt];
		sum[row][rt<<1|1]+=len/2*add[row][rt];
		MAX[row][rt<<1]+=add[row][rt];MAX[row][rt<<1|1]+=add[row][rt];
		MIN[row][rt<<1]+=add[row][rt];MIN[row][rt<<1|1]+=add[row][rt];
		add[row][rt<<1]+=add[row][rt];add[row][rt<<1|1]+=add[row][rt];
		add[row][rt]=0;
	}
}

void ADD(int row,int L,int R,int c,int l,int r,int rt){
	if(l>=L&&r<=R){
		sum[row][rt]+=(r-l+1)*c;
		MAX[row][rt]+=c;
		MIN[row][rt]+=c;
		add[row][rt]+=c;
		return ;
	}
	PushDown(row,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)ADD(row,L,R,c,lson);
	if(R>m)ADD(row,L,R,c,rson);
	PushUp(row,rt);
}

void SET(int row,int L,int R,int c,int l,int r,int rt){
	if(l>=L&&r<=R){
		sum[row][rt]=(r-l+1)*c;
		MAX[row][rt]=c;
		MIN[row][rt]=c;
		add[row][rt]=0;//set操作要先清楚add标记!
		set[row][rt]=c;
		return ;
	}
	PushDown(row,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)SET(row,L,R,c,lson);
	if(R>m)SET(row,L,R,c,rson);
	PushUp(row,rt);
}

int MINVAL,MAXVAL,SUM;
void query(int row,int L,int R,int l,int r,int rt){
	if(l>=L&&r<=R){
		MAXVAL=max(MAXVAL,MAX[row][rt]);
		MINVAL=min(MINVAL,MIN[row][rt]);
		SUM+=sum[row][rt];
		return ;
	}
	PushDown(row,l,r,rt);
	int m=(l+r)/2;
	if(L<=m)query(row,L,R,lson);
	if(R>m)query(row,L,R,rson);
	PushUp(row,rt);
}

int main(){
	int N,M,Q;
	while(~scanf("%d%d%d",&N,&M,&Q)){
		memset(add,0,sizeof(add));
		memset(MAX,0,sizeof(MAX));
		memset(MIN,0,sizeof(MIN));
		memset(sum,0,sizeof(sum));
		memset(set,-1,sizeof(set));

		while(Q--){
			int q;scanf("%d",&q);
			if(q==1){
				int x1,y1,x2,y2,c;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
				for(int i=x1;i<=x2;++i)
					ADD(i,y1,y2,c,1,M,1);
			}else if(q==2){
				int x1,y1,x2,y2,c;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
				for(int i=x1;i<=x2;++i)
					SET(i,y1,y2,c,1,M,1);
			}else{
				int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				MINVAL=INF,MAXVAL=-INF,SUM=0;
				for(int i=x1;i<=x2;++i)
					query(i,y1,y2,1,M,1);
				printf("%d %d %d\n",SUM,MINVAL,MAXVAL);
			}
		}
	}
	return 0;
}
