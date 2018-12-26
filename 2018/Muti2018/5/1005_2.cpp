#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#define eps 1e-6
double a[2],b[2],r[2];
const double PI=acos(-1.0);
int m,R;
double ans=0.0;
double sqr(double x){return x*x;}
double dis(double x1,double y1,double x2,double y2){
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
struct Point{
	double x,y;
	Point(double x=0,int y=0):x(x),y(y){}
};
typedef Point Vector;
int dcmp(double x){
	if(fabs(x)<eps)return 0;
	else return x<0?-1:1;
}
double Dot(Vector A,Vector B){
	return A.x*B.x+A.y*B.y;
}
double Length(Vector A){
	return sqrt(Dot(A,A));
}	
bool operator==(const Point&a,const Point&b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
Vector operator-(Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}

struct Circle{
	Point c;
	double r;
	Circle(Point c,double r):c(c),r(r){}
	Point point(double a){
		return Point(c.x+cos(a)*r+sin(a)*r);
	}
};
double angle(Vector v){return atan2(v.y,v.x);}
//p1,p2为两个交点
Point p1,p2;
int getCircle(Circle C1,Circle C2){
	double d=Length(C1.c-C2.c);
	if(dcmp(d)==0){
		if(dcmp(C1.r-C2.r)==0)return -1;
		return 0;
	}
	if(dcmp(C1.r+C2.r-d)<0)return 0;
	if(dcmp(fabs(C1.r-C2.r)-d)>0)return 0;
	double a=angle(C2.c-C1.c);
	double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	p1=C1.point(a-da),p2=C1.point(a+da);
	//sol.push_back(p1);
	if(p1==p2)return 1;
	//sol.push_back(p2);
	return 2;
}

void solve(int n){
	a[0]=b[0]=0.0;r[0]=R;
	scanf("%lf%lf%lf",&a[1],&b[1],&r[1]);
	double x=dis(a[0],b[0],a[1],b[1]);
	//内切
	if(fabs(R-r[1]-x)<eps){
		ans+=2*PI*r[1];
		return ;
	}

	//外切以及相离,或者内含
	if(x>=r[0]+r[1]||x<fabs(R-r[1])){
		return ;
	}
	//相交
	Point tmp(a[0],b[0]),tmp2(a[1],b[1]);
	int val=getCircle(Circle(tmp,r[0]),Circle(tmp2,r[1]));
	double distance=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));//两个点的距离
	//printf("distance:%.6f\n",distance);
	double alpha=acos((2*R*R-distance)*1.0/(2.0*R*R));
	double beta=acos((2*r[1]*r[1]-distance)*1.0/(2.0*r[1]*r[1]));
	if(x<R){
		ans+=2*PI*r[1]-r[1]*beta-r[0]*alpha;
	}
	else 
	ans+=r[1]*beta-r[0]*alpha;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		ans=0.0;
		scanf("%d%d",&m,&R);
		while(m--){
			solve(2);
			printf("ans=%.6f\n",ans);
		}
		printf("%.6f\n",ans+2*PI*R);
	}
	return 0;
}
