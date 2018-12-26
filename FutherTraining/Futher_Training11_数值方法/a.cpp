#include<cstdio>
#include<cstring>
struct matrix{
	long long a[27][27];
}base,ans;
long long f[27];
long long d,n,m;
matrix muti(matrix x,matrix y){
	matrix tmp;
	for(long long i=1;i<=d;++i){
		for(long long j=1;j<=d;++j){
			tmp.a[i][j]=0;
			for(long long k=1;k<=d;++k){
				tmp.a[i][j]=(tmp.a[i][j]+x.a[i][k]*y.a[k][j])%m;
			}
		}
	}
	return tmp;
}
long long fast_pow(long long n){
	if(n<=d){
		return f[n]%m;
	}
	n-=d;
	for(long long i=1;i<=d;++i){
		for(long long j=1;j<=d;++j){
			if(i==j)ans.a[i][j]=1;
			else ans.a[i][j]=0;
		}
	}
	while(n){
		if(n&1)ans=muti(ans,base);
		base=muti(base,base);
		n/=2;
	}
	long long res=0;
	for(long long i=1;i<=d;++i){
		res=(res+ans.a[1][i]*f[d-i+1])%m;
	}
	return res;
}
int main(){
	while(scanf("%lld%lld%lld",&d,&n,&m)&&d+n+m){
		for(int i=1;i<=d;++i){
			scanf("%lld",&base.a[1][i]);
		}
		for(int i=1;i<=d;++i)scanf("%lld",&f[i]),f[i]%=m;
		for(int i=2;i<=d;++i){
			for(int j=1;j<=d;++j){
				if(j==i-1)base.a[i][j]=1;
				else base.a[i][j]=0;
			}
		}
		printf("%lld\n",fast_pow(n));
	}
	return 0;
}
