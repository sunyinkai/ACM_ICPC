#include<cstdio>
#include<cstring>
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		int i=1,j=(N+1)/2+1;
		for(int k=1;k<=N;++k){
			if(k&1){
				printf("%d ",i);
				++i;
			}else{
				printf("%d ",j);
				++j;
			}
		}
		printf("\n");
	}
	return 0;
}
