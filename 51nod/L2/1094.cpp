#include<cstdio>
const int MAXN=1e4+7;
long long sum[MAXN];
int main(){
	long long N,K;scanf("%lld%lld",&N,&K);
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;++j){
			if(sum[j]-sum[i-1]==K){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("No Solution\n");
	return 0;
}
