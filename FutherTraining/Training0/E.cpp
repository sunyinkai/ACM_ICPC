#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+7;
int a[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+N);
		printf("%d\n",a[(N+1)/2]);
	}
	return 0;
}
