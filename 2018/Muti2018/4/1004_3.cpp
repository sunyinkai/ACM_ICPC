#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=107;
struct node{
	long long x,y;
	bool operator <(const node&other)const{
		return x<other.x||(x==other.x&&y<other.y);
	}
}a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long N,M;scanf("%lld%lld",&N,&M);
		for(int i=0;i<N;++i)
			scanf("%lld%lld",&a[i].x,&a[i].y);
		sort(a,a+N);
		long long ans=M;
		int i;
		for(i=0;i<N;++i){
			if(ans<=a[i].y)break;
			ans=ans/(a[i].x+a[i].y);
		}
		printf("%d\n",i);
	}
	return 0;
}
