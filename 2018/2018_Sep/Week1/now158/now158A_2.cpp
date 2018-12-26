#include<cstdio>
#include<cstring>
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		long long sum=0;
		for(int i=1;i<=N;){
			int val=N/i;
			int r=N/val,l=N/(val+1)+1;
			sum+=(r-l+1)*val;
			i=r+1;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
