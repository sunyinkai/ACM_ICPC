#include<cstdio>
int main(){
	int N,K,C;scanf("%d%d%d",&N,&K,&C);
	int ans;
	if(K/N*N>=C){
		ans=C;
	}else{
		ans=K/N*N;
		C-=K/N*N;//先均分

		int space=N-K%N;
		ans+=space+C;
	}
	printf("%d\n",ans);
	return 0;
}

