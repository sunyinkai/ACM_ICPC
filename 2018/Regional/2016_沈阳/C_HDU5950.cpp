#include<cstdio>
#include<cstring>
typedef  long long LL;
const long long mod=2147493647;
struct matrix{
	LL a[8][8];
}ans,base;
matrix multi(matrix x,matrix y){//X*Y
	matrix t;
	for(int i=1;i<=7;++i){
		for(int j=1;j<=7;++j){
			t.a[i][j]=0;
			for(int k=1;k<=7;++k){
				t.a[i][j]=(t.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
		}
	}
	return t;
}
void show(matrix A){
	for(int i=1;i<=7;++i){
		for(int j=1;j<=7;++j)
			printf("%lld ",A.a[i][j]);
		printf("\n");
	}
	printf("\n");
}

LL B,A,N;
void fast_pow(long long N){
	if(N<=2){
		if(N==1)printf("%lld\n",A);
		else printf("%lld\n",B);
		return;
	}
	N-=2;
	for(int i=1;i<=7;++i)
		for(int j=1;j<=7;++j)
			ans.a[i][j]=(i==j?1:0);
	for(int i=1;i<=7;++i)
		for(int j=1;j<=7;++j)
			base.a[i][j]=0;
	base.a[1][1]=1;base.a[1][2]=2;base.a[1][3]=1;
	base.a[2][1]=1;
	base.a[3][3]=1;base.a[3][4]=4;base.a[3][5]=6;base.a[3][6]=4;
	base.a[3][7]=1;base.a[4][4]=1;base.a[4][5]=3;base.a[4][6]=3;
	base.a[4][7]=1;base.a[5][5]=1;base.a[5][6]=2;base.a[5][7]=1;
	base.a[6][6]=1;base.a[6][7]=1;base.a[7][7]=1;
	while(N){
		if(N&1)ans=multi(ans,base);
		base=multi(base,base);
		N/=2;
	}
	matrix t;
	//show(ans);
	for(int i=1;i<=7;++i)for(int j=1;j<=7;++j)t.a[i][j]=0;
	t.a[1][1]=A;t.a[2][1]=B;t.a[3][1]=81;t.a[4][1]=27;
	t.a[5][1]=9;t.a[6][1]=3;t.a[7][1]=1;
	//show(t);
	ans=multi(ans,t);
	printf("%lld\n",ans.a[1][1]);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&N,&B,&A);
		fast_pow(N);
	}
	return 0;
}
