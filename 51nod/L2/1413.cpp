#include<cstdio>
int main(){
	int N;scanf("%d",&N);
	int ans=0;
	while(N){
		if(N%10>ans)ans=N%10;
		N/=10;
	}
	printf("%d\n",ans);
	return 0;
}
