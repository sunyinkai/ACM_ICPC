#include<cstdio>
#include<cstring>
const long long mod=1e9+7;
struct matrix{
	long long a[9][9];
}base,res;
matrix multi(matrix x,matrix y){
	matrix t;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			t.a[i][j]=0;
			for(int k=0;k<9;++k){
				t.a[i][j]=(t.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
		}
	}
	return t;
}

void fast_pow(long long N){//base^n
	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
			res.a[i][j]=(i==j?1:0);

	while(N){
		if(N&1)res=multi(base,res);
		base=multi(base,base);
		N/=2;
	}
}

long long t[9][9]={
		{0,0,0,1,0,0,1,0,0},
		{1,0,0,1,0,0,1,0,0},
		{1,0,0,1,0,0,0,0,0},
		{0,1,0,0,1,0,0,1,0},
		{0,1,0,0,0,0,0,1,0},
		{0,1,0,0,1,0,0,0,0,},
		{0,0,1,0,0,0,0,0,1,},
		{0,0,0,0,0,1,0,0,1,},
		{0,0,1,0,0,1,0,0,0,},
};

int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long N;scanf("%lld",&N);
		for(int i=0;i<9;++i)
			for(int j=0;j<9;++j)
				base.a[i][j]=t[i][j];
		if(N==1){
			printf("3\n");
			continue;
		}

		fast_pow(N-2);// get:res
		for(int i=0;i<9;++i)base.a[i][0]=1;
		res=multi(res,base);
		long long val=0;
		for(int i=0;i<9;++i)val=(val+res.a[i][0])%mod;
		printf("%lld\n",val);
	}
	return 0;
}
