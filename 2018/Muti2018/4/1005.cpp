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
	for(int i=0;i<2*L;++i){
		for(int j=0;j<2*L;++j){
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
			//printf("sum2[%d][%d]=%d\n",i,j,sum2[i][j]);
		}
	}
}


int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;
		input();
		if(L&1)init(L),n=L;
		else  init(2*L),n=2*L;
		n--;
		//print();
		int m;
		scanf("%d",&m);
		for(int i =0;i<m;i++){
			int x,y,x1,y1,x2,y2;ll ans=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int a=x1%n;
			int b=y1%n;
			int c=y2%n;
			int d=x2%n;
			int l=(y2-y1+1-b)/n;
			int h=(x2-x1+1-a)/n;
			cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<l<<' '<<h<<endl;
			ans+=sum2[a][c];ans+=sum[d][c];ans+=sum2[a][n]-sum2[a][b];
			ans+=sum[d][n]-sum[d][b];
			ans+=(ll)l*(sum2[a][n]+sum[d][n]);
			ans+=(ll)h*(sum2[n][n]-sum[n][b]+sum[n][c]);
			ans+=(ll)l*h*sum[n][n];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
