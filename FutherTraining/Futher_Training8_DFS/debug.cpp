#include<cstdio>
#include<cstring>
int a[2][10] ;
int main(){
	memset(a[1],-1,sizeof(a[1]));
	for(int i=0;i<2;++i){
		for(int j=0;j<10;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
