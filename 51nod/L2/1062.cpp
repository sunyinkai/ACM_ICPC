#include<cstdio>
const int MAXN=1e5+7;
long long a[MAXN];
void init(){
	a[0]=0;a[1]=1;
	for(int i=1;i<MAXN;++i){
		if(a[i]){
			if(2*i<MAXN)a[2*i]=a[i];
			if(2*i+1<MAXN)a[2*i+1]=a[i]+a[i+1];
		}
	}
}
int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		long long ans=0;
		for(int i=0;i<=N;++i)
			if(a[i]>ans)ans=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}
