#include<cstdio>
const int MAXN=1e5+7;
int l[MAXN],r[MAXN],cnt[MAXN];
int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;++i){
		scanf("%d%d",&l[i],&r[i]);
		cnt[i]=r[i]/p-(l[i]-1)/p;
	}
	double ans=0;
	for(int i=0;i<n;++i){
		ans+=(( 1- ( 1-cnt[i]*1.0/(r[i]-l[i]+1) ) * (1- cnt[(i+1)%n]*1.0 / (r[(i+1)%n]-l[(i+1)%n]+1))))*2000;

	}
	printf("%.9f\n",ans);
	return 0;
}
