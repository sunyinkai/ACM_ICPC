//容斥原理,考虑某一行,某一列没有为A,B,C,D;
// all -AUBUCUD
#include<cstdio>
const long long mod=1e6+7;
long long C[507][507];

void init(){
	for(int i=0;i<=500;++i)C[i][0]=1;
	for(int i=1;i<=500;++i){
		for(int j=0;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
int main(){
	int T;scanf("%d",&T);
	init();
	for(int test=1;test<=T;++test){
		long long N,M,K;scanf("%lld%lld%lld",&N,&M,&K);
		long long res=0;
		for(int i=0;i<16;++i){
			int cnt=0;
			long long row=N,col=M;
			if(i&(1<<0))row--,cnt++;
			if(i&(1<<1))row--,cnt++;
			if(i&(1<<2))col--,cnt++;
			if(i&(1<<3))col--,cnt++;
			if(cnt&1)res=(res-C[row*col][K]+mod)%mod;
			else res=(res+C[row*col][K])%mod;
	//		printf("res=%lld\n",res);
		}
		printf("Case %d: %lld\n",test,(res+mod)%mod);
	}
	return 0;
}
