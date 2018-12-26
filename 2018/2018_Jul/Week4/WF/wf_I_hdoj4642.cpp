#include<cstdio>
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,M;scanf("%d%d",&N,&M);
		int num;
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				scanf("%d",&num);
		if(num&1)printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
