#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1007;
int a[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		if(N==1){
			printf("%d\n",a[1]);
			continue;
		}
		sort(a+1,a+N+1);
		int res=0;
		int i;
		if(N&1){//奇数,如3,5,7
			for( i=N;i>=5;i-=2){
				int tmp=0;
				tmp=min(a[i]+2*a[2]+a[1],a[i]+a[i-1]+2*a[1]);
				res+=tmp;
			}
			res+=a[1]+a[2]+a[3];
		}else{
			for(i=N;i>=4;i-=2){
				int tmp=0;
				tmp=min(a[i]+2*a[2]+a[1],a[i]+a[i-1]+2*a[1]);
				res+=tmp;
			}
			res+=max(a[2],a[1]);
		}
		printf("%d\n",res);
	}
	return 0;
}
