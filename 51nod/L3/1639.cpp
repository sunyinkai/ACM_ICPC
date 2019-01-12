#include<cstdio>
int main(){
	int N;scanf("%d",&N);
	double ans=1.0;
	for(int i=2*N-2;i>0;i-=2)
		ans=ans*1.0*i/(i+1);
	printf("%.6f\n",ans);
	return 0;
}
