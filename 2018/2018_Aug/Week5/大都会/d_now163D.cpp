#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define pi acos(-1)
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N,L,S;scanf("%d%d%d",&N,&L,&S);
		double alpha=pi*1.0/N;
		double S0=(double)N*L*L/tan(alpha)/4.0;
	//	printf("S0=%.6f\n",S0);
		int res=0;
		while(S0>S){
			++res;
			S0=S0*(1-sin(2*alpha)*tan(alpha)/2.0);
	//		printf("S0=%.6f\n",S0);
		}
		printf("%d\n",res);
	}
	return 0;
}
