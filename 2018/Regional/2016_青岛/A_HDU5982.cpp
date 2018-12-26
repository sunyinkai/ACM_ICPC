#include<cstdio>
#include<cstring>
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		long long res=0;
		for(int i=0;i<N;++i){
			long long x,y;scanf("%lld%lld",&x,&y);
			res+=x*y;
		}
		printf("%lld\n",res);
	}
	return 0;
}
