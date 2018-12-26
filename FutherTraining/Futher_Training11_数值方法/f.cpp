//下凸函数求极值
//三分
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
const double INF=1e12;
int a[MAXN],b[MAXN],c[MAXN];
int n;
double getVal(double mid){
	double res=-INF;
	for(int i=0;i<n;++i){
		double tmp=a[i]*mid*mid+b[i]*mid+c[i];
		res=max(res,tmp);
	}
	return res;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
		double lo=0.0,hi=1000.0;
		for(int i=0;i<100;++i){
			double mid=(hi+lo)/2.0;
			double R=(mid+hi)/2.0;
			double midVal=getVal(mid);
			double RVal=getVal(R);
			if(midVal>RVal)lo=mid;
			else  hi=R;
			//printf("lo=%.6f,hi=%.6f\n",lo,hi);
		}
		printf("%.4f\n",getVal(hi));
	}
	return 0;
}

