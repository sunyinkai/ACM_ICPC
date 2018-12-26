#include<cstdio>
const int MAXN=1e6+7;
int a[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		long long sum=0;
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			sum^=x;
		}
		if(sum==0)printf("Second player wins.\n");
		else printf("First player wins.\n");
	}
	return 0;
}
