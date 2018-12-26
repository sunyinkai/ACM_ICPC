#include<cstdio>
#include<cstring>
typedef long long LL;
const int MAXN=27;
const LL mod=1e9+9;

LL N;
struct matrix{
	LL a[MAXN][MAXN];
};

LL a[MAXN],k[MAXN];
matrix muti(matrix x,matrix y){
	matrix t;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j){
			t.a[i][j]=0;
			for(int k=1;k<=N;++k){
				t.a[i][j]=(t.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
		}
	return t;
}
LL fast_pow(LL n){
	matrix base,ans;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			ans.a[i][j]=(i==j?1:0);//单位矩阵
	for(int i=1;i<=N;++i)
		base.a[1][i]=k[N-i+1];
	for(int i=2;i<=N;++i)
		for(int j=1;j<=N;++j)
			base.a[i][j]=(j+1==i?1:0);
	while(n){
		if(n&1)ans=muti(ans,base);
		base=muti(base,base);
		n/=2;
	}
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			base.a[i][j]=(j==1?a[N-i+1]:0);
	ans=muti(ans,base);
	return ans.a[1][1];
}

int main(){
	LL m,c;
	scanf("%lld%lld%lld",&N,&m,&c);
	for(int i=1;i<=N;++i){
		scanf("%lld",&a[i]);
		a[i]%=mod;
	}
	for(int i=1;i<=c;++i){
		int x;scanf("%d",&x);
		k[N-x+1]=1;
	}
	if(m<=N){
		printf("%lld\n",a[m]);
	}else{
		printf("%lld\n",fast_pow(m-N));
	}
	return 0;
}
