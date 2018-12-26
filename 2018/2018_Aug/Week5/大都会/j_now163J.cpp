#include<cstdio>
#include<cstring>
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		long long N;scanf("%lld",&N);
		printf("Case %d: ",test);
		if(N<=10){
			printf("%lld\n",N);
		}else{
			long long res=0;
			res+=N/10;
			res+=N/3;
			res-=N/30;
			res+=6;
			printf("%lld\n",res);
		}
	}
	return 0;
}
