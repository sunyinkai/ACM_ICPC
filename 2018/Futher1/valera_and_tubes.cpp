#include<cstdio>
int main(){ 
	int N,M,K;scanf("%d%d%d",&N,&M,&K);
	if(K<=N){ 
		for(int i=1;i<=K-1;++i){ 
			printf("%d ",M);
			for(int j=1;j<=M;++j){ 
				printf("%d %d ",i,j);
			}
			printf("\n");
		}
		printf("%d ",(N-K+1)*M);
		for(int i=K;i<=N;++i){ 
			if(i&1)for(int j=1;j<=M;++j)printf("%d %d ",i,j);
			else for(int j=M;j>=1;--j)printf("%d %d ",i,j);
		}
		printf("\n");
	}else{ 
		int hasDone=0,cnt=0;
		int i,j;
		for(i=1;i<=N;){ 
			for(j=1;j<=M;++j){ 
				if(cnt%2==0){ 
					++hasDone;
					if(hasDone==K)break;
					printf("2 ");
				}
				printf("%d %d ",i,j);++cnt;
				if(cnt%2==0)printf("\n");
			}

			if(hasDone==K)break;
			++i;
			for(j=M;j>=1;--j){ 
				if(cnt%2==0){ 
					++hasDone;
					if(hasDone==K)break;
					printf("2 ");
				}
				printf("%d %d ",i,j);++cnt;
				if(cnt%2==0)printf("\n");
			}
			if(hasDone==K)break;
			++i;
		}
		
		printf("%d ",N*M-(K-1)*2);
		if(i&1)
			for(;j<=M;++j)printf("%d %d ",i,j);
		else 
			for(;j>=1;--j)printf("%d %d ",i,j);
		++i;
		for(;i<=N;++i){ 
			if(i&1){ 
				for(j=1;j<=M;++j)printf("%d %d ",i,j);
			}else{ 
				for(j=M;j>=1;--j)printf("%d %d ",i,j);
			}
		}
	}
	return 0;
}
