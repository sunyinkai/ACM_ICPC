#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define eps 1e-4
const int MAXN=1e5+7;
double x[MAXN],y[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i)
			scanf("%lf%lf",&x[i],&y[i]);
		double xx,yy,rr;

		if(N<=4){
			if(N==1)x[1]=x[0]+100,y[1]=y[0]+107;
			++N;
			if(N>=2){
				double xx=(x[0]+x[1])/2.0,yy=(y[0]+y[1])/2.0;
				printf("%.4f %.4f %.4f\n",xx,yy,sqrt((xx-x[0])*(xx-x[0])+(yy-y[0])*(yy-y[0])));
			}
			continue;
		}
		for(int id=0;;++id){
			int a,b,c;
			while(1){
				a=rand()%N;b=rand()%N;c=rand()%N;
				if(a!=b&&b!=c&&a!=c)break;
			}

			//求三角形外接圆的圆心以及半径
			int res=0;
			double x1=x[a],y1=y[a];
			double x2=x[b],y2=y[b];
			double x3=x[c],y3=y[c];
			if((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)==0)continue;
			if((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)==0)continue;
			xx=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
			yy=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));
			rr=(xx-x1)*(xx-x1)+(yy-y1)*(yy-y1);

			for(int i=0;i<N;++i){//check
				double r0=(xx-x[i])*(xx-x[i])+(yy-y[i])*(yy-y[i]);
				if(fabs(r0-rr)<eps){
					//printf("i=%d\n",i);
					++res;
				}
				if(res>=(N+1)/2)break;
			}
			if(res>=(N+1)/2)break;
			printf("\n");
		}
		printf("%.4f %.4f %.4f\n",xx,yy,sqrt(rr));
	}
	return 0;
}
