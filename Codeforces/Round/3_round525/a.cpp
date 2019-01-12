#include<cstdio>
int main(){
	int x;scanf("%d",&x);
	for(int a=1;a<=100;++a){
		int b;
		for(int j=1;j<=100;++j){
			b=j*a;
			if(b>=100)continue;
			if(a*b>x&&b/a<x){
				printf("%d %d\n",b,a);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
