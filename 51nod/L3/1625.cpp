#include<bits/stdc++.h>
using namespace std;
const int MAXN=11,MAXM=201;
long long a[MAXN][MAXM];
int N,M,x,cnt;
long long t[MAXN][MAXM];

long long sum_col(int x){
	long long ans=0;
	for(int i=1;i<=N;++i)
		ans+=t[i][x];
	return ans;
}


int main(){
	scanf("%d%d%d%d",&N,&M,&x,&cnt);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			scanf("%lld",&a[i][j]);

	long long ans=0;
	for(int k=0;k<(1<<N);++k){//横着涂
		int cnt_row=__builtin_popcount(k);//横着涂的数量
		if(cnt_row<=cnt){
			long long tmp_ans=0;
			for(int i=1;i<=N;++i)//先染横着的
				for(int j=1;j<=M;++j){
					t[i][j]=(k&(1<<(i-1)))?x:a[i][j];
					tmp_ans+=t[i][j];
				}
		
			//贪心
			long long q[MAXM];int top=0;
			for(int i=1;i<=M;++i){
				q[top++]=sum_col(i);
			}
			sort(q,q+top);

			int cnt_col=cnt-cnt_row;
			for(int i=0;(i<min(top,cnt_col))&&(q[i]<=(long long)x*N);++i){
				tmp_ans+=(long long)x*N-q[i];
			}
			ans=max(ans,tmp_ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
