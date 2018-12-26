#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int MAXN=1e6+7;
const int INF=1e9+7;
int a[21][MAXN<<2];
int set[21][MAXN<<2],add[21][MAXN<<2];
int sum[21][MAXN<<2],Max[21][MAXN<<2],Min[21][MAXN<<2];
int maxVal,minVal,sumVal;
void PushUp(int tree,int rt){
	Max[tree][rt]=max(Max[tree][rt<<1],Max[tree][rt<<1|1]);
	Min[tree][rt]=min(Min[tree][rt<<1],Min[tree][rt<<1|1]);
	sum[tree][rt]=sum[tree][rt<<1]+sum[tree][rt<<1|1];
}//自底向上更新

void PushDown(int tree,int rt,int len){
	if(set[tree][rt]){
		add[tree][rt<<1]=add[tree][rt<<1|1]=0;//?!
		set[tree][rt<<1]=set[tree][rt<<1|1]=set[tree][rt];

		sum[tree][rt<<1]=set[tree][rt]*(len-len/2);
		sum[tree][rt<<1|1]=set[tree][rt]*(len/2);
		Max[tree][rt<<1]=Max[tree][rt<<1|1]=set[tree][rt];
		Min[tree][rt<<1]=Min[tree][rt<<1|1]=set[tree][rt];//v
		set[tree][rt]=0;
	}
	if(add[tree][rt]){
		sum[tree][rt<<1]+=add[tree][rt]*(len-len/2);
		sum[tree][rt<<1|1]+=add[tree][rt]*(len/2);
		Max[tree][rt<<1]+=add[tree][rt];
		Max[tree][rt<<1|1]+=add[tree][rt];
		Min[tree][rt<<1]+=add[tree][rt];//v
		Min[tree][rt<<1|1]+=add[tree][rt];

		add[tree][rt<<1]+=add[tree][rt];
		add[tree][rt<<1|1]+=add[tree][rt];
		add[tree][rt]=0;
	}
}//自顶向下传递标记
void update(int tree,int kind,int L,int R,int val,int l,int r,int rt){//kind==2 set kind==1 add
	if(l>=L&&r<=R){
		if(kind==1){//add
			add[tree][rt]+=val;
			sum[tree][rt]+=val*(r-l+1);
			Max[tree][rt]+=val;
			Min[tree][rt]+=val;
		}else{//set
			set[tree][rt]=val;
			add[tree][rt]=0;
			sum[tree][rt]=val*(r-l+1);
			Max[tree][rt]=Min[tree][rt]=val;
		}
		return;
	}
	PushDown(tree,rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)update(tree,kind,L,R,val,lson);
	if(R>m) update(tree,kind,L,R,val,rson);
	PushUp(tree,rt);
}
void query(int tree,int L,int R,int l,int r,int rt){
	//printf("l=%d,r=%d,L=%d,R=%d\n",l,r,L,R);//(1,3) (1,3)
	if(l>=L&&r<=R){
		maxVal=max(maxVal,Max[tree][rt]);
		minVal=min(minVal,Min[tree][rt]);
		sumVal+=sum[tree][rt];
		return;
	}
	PushDown(tree,rt,r-l+1);
	int m=(l+r)/2;
	if(L<=m)query(tree,L,R,lson);
	if(R>m) query(tree,L,R,rson);
	PushUp(tree,rt);//???
}
int main(){
	int N,M,T;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d%d",&N,&M,&T)){
		memset(set,0,sizeof(set));
		memset(add,0,sizeof(add));
		memset(Max,0,sizeof(Max));
		memset(Min,0,sizeof(Min));
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));

		while(T--){
			int op;scanf("%d",&op);
			if(op==1){
				int x1,y1,x2,y2,val;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
				for(int i=x1;i<=x2;++i){
					update(i,1,y1,y2,val,1,M,1);
				}
			}else if(op==2){
				int x1,y1,x2,y2,val;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&val);
				for(int i=x1;i<=x2;++i){
					update(i,2,y1,y2,val,1,M,1);
				}
			}else{
				int x1,x2,y1,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				maxVal=-INF,minVal=INF,sumVal=0;
				for(int i=x1;i<=x2;++i){
	//				printf("i=%d,y1=%d,y2=%d\n",i,y1,y2);
					query(i,y1,y2,1,M,1);
				}
				printf("%d %d %d\n",sumVal,minVal,maxVal);
			}
		}
	}
	return 0;
}
