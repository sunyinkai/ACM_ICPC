#include<cstdio>
#include<cmath>
#define eps 1e-8
int main(){
	int T;scanf("%d",&T);
	while(T--){
		double a,b,S;scanf("%lf%lf%lf",&a,&b,&S);
		if(S==0){
			printf("%.6f%%\n",100.0);
			continue;
		}else if(S-a*b>eps){
			printf("%.6f%%\n",0.0);
			continue;
		}
		double fenzi=a*b*1.0-S-S*log(a*b*1.0/S);
		double fenmu=2*a*b*1.0;
		printf("%.6f%%\n",fenzi/fenmu*200);
	}
	return 0;
}
