//精度会有问题

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define eps 1e-7
using namespace std;

const int MAXN=107;
long double a[MAXN];
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){
			double x,y;
			scanf("%lf:%lf",&x,&y);
			 //x=floor(x*1000),y=floor(y*1000);
			a[i]=(long double)x*1.0/(x+y);
		}
		sort(a,a+N);
		int res=0;
		long double sum=0.0;
		for(int i=0;i<N;++i){
			sum+=a[i];
			if(sum>=1)break;
			++res;
		}
		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}
