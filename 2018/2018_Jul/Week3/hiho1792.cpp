#include<cstdio>
#include<cstring>
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;;++i){
		if((1<<i)&n)break;
	}
	printf("%d\n",i+1);
	return 0;
}
