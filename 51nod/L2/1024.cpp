#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=107;
const double eps=1e-7;
double ans[MAXN*MAXN];
int main(){
	int m,n,a,b;scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			double x=a+i,y=b+j;
			ans[i*n+j]=(double)1.0*y*log(x*1.0);
		}
	}
	sort(ans,ans+m*n);
	double prev=ans[0];	
	int cnt=0;
	for(int i=1;i<m*n;++i){
		if(fabs(ans[i]-prev)<eps){
		}else{
			++cnt;
			prev=ans[i];
		}
	}
	printf("%d\n",cnt+1);
	return 0;
}
