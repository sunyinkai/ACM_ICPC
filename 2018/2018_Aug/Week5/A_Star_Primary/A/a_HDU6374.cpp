#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1007;
int a[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		sort(a,a+N);
		int res=-1;
		for(int i=0;i<N-2;++i){
			if(a[i]+a[i+1]>a[i+2]){
				res=a[i]+a[i+1]+a[i+2];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
