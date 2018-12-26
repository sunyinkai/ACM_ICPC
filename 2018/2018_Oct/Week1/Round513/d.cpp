#include<cstdio>
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
int main(){
	int N;scanf("%d",&N);
	long long ans1=0,ans2=0;
	for(int i=1;i<=N;++i){
		long long l,r;scanf("%lld%lld",&l,&r);
		ans1+=l,ans2+=r;
	}
	printf("%lld\n",max(ans1,ans2)+N);
	return 0;
}
