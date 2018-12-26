#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+1;
long long A[MAXN];
void init(){
	A[0]=A[1]=0;
	for(long long i=2;i<MAXN;++i){
		A[i]=A[i-1]+i*(i-1);
	}
}
int main(){
	long long N,M;
	init();
	while(~scanf("%lld%lld",&N,&M)&&N+M){
		long long res=N*M*(N+M-2);
		long long x=min(N,M);
		long long tmp=0;
		tmp+=A[x-1]*2;
		tmp+=(N+M-1-2*(x-1))*x*(x-1);
		res+=tmp*2;
		printf("%lld\n",res);
	}
	return 0;
}
