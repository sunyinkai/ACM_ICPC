#include<cstdio>
#include<cstring>
#include<cmath>
#define min(a,b) (a<b?a:b)
#define PI acos(-1)
const int MAXN=1e6;
const int INF=1e9+7;
int main(){
	double base=2*PI/MAXN;
	int r,x1,y1,x2,y2;
	scanf("%d",&r);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	double res=INF;
	for(int i=0;i<MAXN;++i){
		double x=r*sin(base*i);
		double y=r*cos(base*i);
		double dis=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		dis+=sqrt((x2+x)*(x2+x)+(y+y2)*(y+y2));
		if(dis<res)res=dis;
	}
	printf("%.9f\n",min(res,sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))));
	return 0;
}
