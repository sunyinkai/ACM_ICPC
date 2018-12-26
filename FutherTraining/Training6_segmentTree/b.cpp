#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int left[MAXN],right[MAXN],f[MAXN][20]; int Q(int l,int r){
	int k=0;
	while((1<<(k+1))<=r-l+1)k++;
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		int q;scanf("%d",&q);
		int prev=-1e5+7,cnt=0,tot=0;
		for(int i=1;i<=N;++i){
			int x;scanf("%d",&x);	
			if(x==prev){
				++cnt;
			}else{
				f[tot][0]=cnt;//tot从1开始0没有用
				left[++tot]=i;//区间左端点
				prev=x;
				cnt=1;
			}
		}
		f[tot][0]=cnt;
		left[++tot]=N;
		for(int i=0;i<tot;++i){
			if(i+1!=tot)right[i]=left[i+1]-1;
			else right[i]=left[i+1];
		}
		for(int i=0;i<tot;++i){
			//printf("i=%d,left=%d,right=%d\n",i,left[i],right[i]);
		}
		for(int k=1;k<20;++k)
			for(int i=0;i+(1<<k)-1<tot;++i)
				f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);

		while(q--){
			int x,y;scanf("%d%d",&x,&y);
			int ll=lower_bound(left,left+tot,x)-left;
			int rr=upper_bound(right,right+tot,y)-right-1;
			if(lower_bound(right,right+tot,y)==lower_bound(right,right+tot,x)){
				printf("%d\n",y-x+1);
				continue;
			}
			int res=0;
			if(ll<=rr){
				res=Q(ll,rr);
			}
	//		printf("ll=%d,rr=%d,res=%d,left=%d,right=%d\n",ll,rr,res,left[ll]-x,y-right[rr]);
			res=max(res,left[ll]-x);
			res=max(res,y-right[rr]);
			printf("%d\n",res);
		}
	}
	return 0;
}
