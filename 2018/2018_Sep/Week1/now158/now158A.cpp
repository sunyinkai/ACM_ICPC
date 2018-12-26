//1...N中因子个数之和
//N/1+N/2+N/3+N/4+...
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int Q;scanf("%d",&Q);
	while(Q--){
		int N;scanf("%d",&N);
		long long sum=0;
		for(int i=1;i<=N;){
			int val=N/i;
			int l=N/(val+1)+1,r=N/val;
			i=r+1;
			sum+=(r-l+1)*val;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
