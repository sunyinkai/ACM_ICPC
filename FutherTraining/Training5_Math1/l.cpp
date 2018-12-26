#include<cstdio>
#include<math.h>
const int MAXN=1007;
double p[MAXN];
double f[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int n,k,m;scanf("%d%d%d",&n,&k,&m);
		for(int i=0;i<n;++i)scanf("%lf",&p[i]);
		f[0]=0;f[1]=p[0];
		for(int i=1;i<m;++i){
			f[i+1]=p[0];
			for(int j=1;j<n;++j){
				f[i+1]+=pow(f[i],j)*p[j];
			}
		}
		printf("Case #%d: %.6f\n",test,pow(f[m],k));
	}
	return 0;
}
