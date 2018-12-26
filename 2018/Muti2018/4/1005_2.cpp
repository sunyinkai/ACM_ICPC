#include<bits/stdc++.h>
using namespace std;

const int MAXN=47;
typedef long long ll;
int a[MAXN][MAXN],A[MAXN];
int sum[MAXN][MAXN],sum2[MAXN][MAXN];
int L;


void generate(){
	int cursor=0;
	for(int i=0;i<MAXN;++i){
		for(int j=0;j<=i;++j){
			a[j][i-j]=A[cursor];
			cursor=(cursor+1)%L;
		}
	}
}
void input(){
	scanf("%d",&L);
	for(int i=0;i<L;++i)scanf("%d",&A[i]);
	generate();
}


inline int add(int i,int j){
	if(i<0)return 0;
	if(j<0)return 0;
	return sum[i][j];
}
inline int add2(int i,int j,int N){
	if(i>=N||i<0)return 0;
	if(j>=N||j<0)return 0;
	return sum2[i][j];
}

void print(){
	for(int i=0;i<20;++i){
		for(int j=0;j<20;++j){
			if(a[i][j])printf("%d ",a[i][j]);
			else break;
		}
		printf("\n");
	}
}

//sum:左上开始，sum2:左下开始
void init(int N){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			sum[i][j]=add(i-1,j)+add(i,j-1)-add(i-1,j-1)+a[i][j];
		//	printf("sum[%d][%d]=%d\n",i,j,sum[i][j]);
		}
	}
	for(int i=N-1;i>=0;--i){
		for(int j=0;j<N;++j){
			sum2[i][j]=add2(i+1,j,N)+add2(i,j-1,N)-add2(i+1,j-1,N)+a[i][j];
		}
	}
}


int block=0;
long long getRes(int x,int y){
	long long ans=0;
	//printf("blcok=%lld\n",sum[block-1][block-1]);
	ans+=(long long)(x+1)/block*(y+1)/block*sum[block-1][block-1];
	ans+=x/block*sum2[0][y%block];
	ans+=y/block*sum[x%block][block-1];
	if(x%block!=0&&y%block!=0)ans+=sum[x%block][y%block];
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;
		input();
		if(L&1)init(L),n=L;
		else  init(2*L),n=2*L;
	//	printf("%d\n",sum[n-1][n-1]);
		int m;
		scanf("%d",&m);
		for(int i =0;i<m;i++){
			block=n;
			int x1,y1,x2,y2; ll ans=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ans+=getRes(x2,y2);
			ans-=getRes(x2,y1-1);
			ans-=getRes(x1-1,y2);
			ans+=getRes(x1-1,y1-1);
			printf("%lld\n",ans);
			
		}
	}
	return 0;
}

