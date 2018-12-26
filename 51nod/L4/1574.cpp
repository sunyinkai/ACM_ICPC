#include<cstdio>
#include<cstdlib>
const int MAXN=2e5+7;
int p[MAXN],a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		p[x]=i;
	}
	long long ans=0;
	for(int i=1;i<=N;++i){
		int x;
		scanf("%d",&x);
		x=p[x];
		ans+=abs(i-x);
	}
	printf("%lld\n",ans/2);
	return 0;
}
