#include<cstdio>
#include<cstring>
const int MAXN=1007;
int a[MAXN],b[MAXN];
int N,M;

bool isok(double x){
	for(int i=0;i<N;++i){
		double all=x+M;
		x-=all*1.0/a[i];
		if(x<0)return false;
		all=x+M;
		x-=all*1.0/b[i+1];
		if(x<0)return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<N;++i)
		scanf("%d",&b[i]);
	b[N]=b[0];
	double hi=1e9+7,lo=0.0;
	for(int i=0;i<100;++i){
		double mid=(hi+lo)/2;
		if(isok(mid))hi=mid;
		else lo=mid;
	}
	if(hi>1e9+2)printf("-1\n");
	else printf("%.8f\n",hi);
	return 0;
}
