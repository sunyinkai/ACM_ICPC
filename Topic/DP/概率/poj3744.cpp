#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;double p;
int a[15];
struct matrix{
	double a[2][2];
};
matrix muti(matrix x,matrix y){
	matrix t;
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			t.a[i][j]=0;//init
			for(int k=0;k<2;++k){
				t.a[i][j]+=1.0*x.a[i][k]*y.a[k][j];
			}
		}
	}
	return t;
}
double getP(int n){
	matrix ans,base;
	ans.a[0][0]=1;ans.a[0][1]=ans.a[1][0]=ans.a[1][1]=0;
	base.a[0][0]=p;base.a[0][1]=1-p;base.a[1][0]=1.0;base.a[1][1]=0.0;
	if(n<0)return 0;
	while(n){
	//	printf("n=%d\n",n);
		if(n&1)ans=muti(base,ans);
		base=muti(base,base);
		n/=2;
	}
	return ans.a[0][0];
}
int main(){
	while(~scanf("%d%lf",&N,&p)){
		for(int i=0;i<N;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+N);
		double res=1.0;
		int prev=1;
		for(int i=0;i<N;++i){
			res=res*(1-p)*getP(a[i]-prev-1);
			prev=a[i]+1;
		}
		printf("%.7f\n",res);
	}
	return 0;
}

