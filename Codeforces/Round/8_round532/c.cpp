#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int main(){
	double n,r;scanf("%lf%lf",&n,&r);
	double ans=r*sin(PI/n)/(1-sin(PI/n));
	printf("%.8f\n",ans);
	return 0;
}
