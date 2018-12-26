#include<cstdio>
#include<cstring>
int main(){
	freopen("in.txt","w",stdout);
	printf("1\n");
	printf("20 190 10\n");
	for(int i=1;i<=20;++i)
		for(int j=i+1;j<=20;++j)
			printf("%d %d\n",i,j);
	return 0;
}
