#include<cstdio>
int main(){
	long long N;scanf("%lld",&N);
	int a[4]={2,3,5,7};
	long long ans=N;
	for(int i=1;i<(1<<4);++i){
		long long val=1;
		int cnt=0;
		for(int k=0;k<4;++k){
			if(i&(1<<k))val*=a[k],++cnt;
		}
		if(cnt&1)ans-=N/val;
		else ans+=N/val;
	}
	printf("%lld\n",ans);
	return 0;
}
