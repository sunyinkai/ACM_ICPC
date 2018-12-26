#include<cstdio>
const int MAXN=1e5+7;
const int MAXM=5e6+7;
long long even[MAXN],odd[MAXN];
long long a[MAXM];
void init(){
	for(long long i=1;i<MAXM;++i)
		a[i]=i*i;
}

int main(){
	init();
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%lld",&even[i]);
	long long base=1;
	for(i=1;i<=N;++i){

	}
	return 0;
}
