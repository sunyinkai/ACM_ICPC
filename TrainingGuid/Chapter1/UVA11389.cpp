#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=107;
int a[MAXN],b[MAXN];
int main(){
	int n,d,r;
	while(scanf("%d%d%d",&n,&d,&r)&&n+d+r){
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i)scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int res=0;
		for(int i=0;i<n;++i){
			res+=max(0,(a[i]+b[n-1-i]-d)*r);
		}
		printf("%d\n",res);
	}
	return 0;
}
