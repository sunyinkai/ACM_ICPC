#include<cstdio>
// LL inv(LL t,LL p) t在%p意义下的逆元
//	return t==1?1:(p-p/t)*inv(p%t,p)%p;
const  int MAXN=3e6+7;
long long inv[MAXN];
int main(){
	long long  n,p;scanf("%lld%lld",&n,&p);
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=(p-p/i)*1ll*inv[p%i]%p;
	}
	for(int i=1;i<=n;++i){
		printf("%lld\n",inv[i]);
	}
}
