#include<cstdio>
#include<cstring>
#include<cmath>
const int MAXN=1e5+7;
int a[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		printf("%d\n",(int)sqrt(fabs(a[N]-a[1])));
	}
	return 0;
}
