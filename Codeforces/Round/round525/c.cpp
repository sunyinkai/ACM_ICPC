#include<cstdio>
const int MAXN=2007;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
	}
	printf("%d\n",N+1);
	printf("1 %d 600000\n",N);
	for(int i=1;i<=N;++i)a[i]+=(int)6e5;
	for(int i=1;i<=N;++i){
		printf("2 %d %d\n",i,a[i]-i);
	}
	return 0;
}

