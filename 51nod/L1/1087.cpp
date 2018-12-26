#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
long long x[MAXN];
void init(){
	for(long long i=1;i<MAXN;++i)
		x[i]=(i*i-i+2)/2;
}
int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		long long N;scanf("%lld",&N);
		int cnt=upper_bound(x+1,x+MAXN,N)-lower_bound(x+1,x+MAXN,N);
		if(cnt)printf("1\n");
		else printf("0\n");
	}
	return 0;
}
