#include<cstdio>
int a[107];
int main(){
	int n;scanf("%d",&n);
	long long res=1;
	int tot=0;
	for(int i=1;i<=n;++i){
		int x;scanf("%d",&x);
		if(x==1){
			a[tot++]=i;
		}
	}
	if(tot<=1){
		printf("%d\n",tot);
		return 0;
	}
	for(int i=1;i<tot;++i){
		res*=(a[i]-a[i-1]);
	}
	printf("%lld\n",res);
	return 0;
}
