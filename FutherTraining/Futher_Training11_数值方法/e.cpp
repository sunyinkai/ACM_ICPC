#include<cstdio>
#include<cmath>
#define eps 1e-10
int p,q,r,s,t,u;
double  F(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
	while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)){
		if(F(1)>eps||F(0)<-eps){
			printf("No solution\n");
			continue;
		}
		double lo=0,hi=1;
		for(int i=0;i<100;++i){
			double mid=(hi+lo)/2.0;
			if(F(mid)<0)hi=mid;
			else lo=mid;
		}
		printf("%.4f\n",hi);
	}
	return 0;
}
