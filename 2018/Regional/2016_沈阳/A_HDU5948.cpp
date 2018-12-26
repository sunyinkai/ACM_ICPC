#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int A,B;scanf("%d%d",&A,&B);
		printf("%d\n",max(2*A+B,2*B+A));
	}
}
