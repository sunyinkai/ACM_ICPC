#include<cstdio>
const int MAXN=1e6+7;
long long sum[MAXN];
void init(){
	for(int i=1;i<MAXN;++i){
		long long isok=i;
		if(i%7==0)isok=0;
		int num=i;
		while(num){
			if(num%10==7)isok=0;
			num/=10;
		}
		sum[i]=sum[i-1]+isok*isok;
	}
}
int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		printf("%lld\n",sum[N]);
	}
	return 0;
}
