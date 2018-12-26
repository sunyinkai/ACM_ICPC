#include<cstdio>
const int MAXN=15;
double a[MAXN];
int N;
double power(double x,double n){
	double res=1.0;
	for(int i=0;i<n;++i)res*=x;
	return res;
}
double get_val(double x){
	double res=0.0;
	for(int i=0;i<=N;++i){
		res+=1.0*a[i]*power(x,i);
	}
	return res;
}
int main(){
	double l,r;
	scanf("%d%lf%lf",&N,&l,&r);
	for(int i=N;i>=0;--i)scanf("%lf",&a[i]);
	for(;r-l>0.000001;){
		double lm=l+(r-l)/3.0;
		double rm=r-(r-l)/3.0;
		if(get_val(lm)<=get_val(rm))l=lm;
		else r=rm;
	}
	printf("%.5f\n",l);
	return 0;
}
