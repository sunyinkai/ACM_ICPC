#include<cstdio>
#include<cstring>
long long n,k,P;
long long fast_muti(long long base,long long n){
	long long res=0;
	while(n){
		if(n&1)res=(res+base)%P;
		base=(base+base)%P;
		n/=2;
	}
	return res;
}
long long fast_pow(long long base,long long n){
	long long res=1;
	while(n){
		if(n&1)res=fast_muti(res,base);
		base=fast_muti(base,base);
		n/=2;
	}
	return res;
}
int main(){
	scanf("%lld%lld%lld",&n,&k,&P);
	printf("%lld\n",fast_pow(k,n));
	return 0;
}
