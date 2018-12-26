#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
int main(){ 
	freopen("in.txt","w",stdout);
	printf("10\n");
	srand(time(NULL));

	for(int t=1;t<=10;++t){ 
		 int N=1e5;
		printf("%d\n",N);
		for(int i=0;i<N;++i)
			printf("%d ",rand()%(100000+1));
	}
	return 0;
}
