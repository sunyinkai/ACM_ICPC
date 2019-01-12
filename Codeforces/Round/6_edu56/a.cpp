#include<cstdio>
#define max(a,b) (a>b?a:b)
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		int ans=0;
		if(N&1){
			ans=max(N/2-1,1);
		}else{
			ans=N/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
