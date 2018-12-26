#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
const int INF=1e9+7;
int big[1000],small[1000];
int a[MAXN];
int main(){
	int N,Q;
	while(~scanf("%d%d",&N,&Q)){
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		for(int i=0;i<1000;++i)big[i]=-INF,small[i]=INF;
		int sz=sqrt(N);
		for(int i=0;i<N;++i){
			big[i/sz]=max(big[i/sz],a[i]);
			small[i/sz]=min(small[i/sz],a[i]);
		}
		for(int i=0;i<Q;++i){
			int l,r;scanf("%d%d",&l,&r);
			l--;r--;
			int lo,hi;
			if(l%sz==0)lo=l/sz;//新区间
			else lo=l/sz+1;
			hi=r/sz;

	//		printf("lo=%d,hi=%d\n",lo,hi-1);
			int most=-INF,less=INF;
			for(int i=lo;i<hi;++i){
				most=max(most,big[i]);
				less=min(less,small[i]);
			}
			if(l/sz==r/sz){//同一块内
				for(int i=l;i<=r;++i){
					most=max(most,a[i]);
					less=min(less,a[i]);
				}
			}else{
				for(int i=l;i%sz!=0;++i){//左边
					most=max(most,a[i]);
					less=min(less,a[i]);
				}
	//			printf("most=%d,less=%d\n",most,less);
				for(int i=r;;--i){
					most=max(most,a[i]);
					less=min(less,a[i]);
					if(i%sz==0)break;
				}
	//			printf("most=%d,less=%d\n",most,less);
			}
			printf("%d\n",most-less);
		}
	}
	return 0;
}

