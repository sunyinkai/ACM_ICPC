#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}A,B,C;
typedef Point Vector;

Vector operator-(Point A,Point B){
	return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Point A,double p){
	return Vector(A.x*p,A.y*p);
}
Vector operator+(Point A,Point B){
	return Vector(A.x+B.x,A.y+B.y);
}
Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){
	return acos(Dot(A,B)/Length(A)/Length(B));
}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}

void solve(Point B,Point C,Point A){
	double alpha=Angle(C-B,A-B);
	double beta=Angle(B-C,A-C);
	Vector v=Rotate(C-B,alpha/3.0);
	Vector w=Rotate(B-C,-beta/3.0);
	Point t=GetLineIntersection(B,v,C,w);
	printf("%.7f %.7f ",t.x,t.y);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		solve(B,C,A);
		solve(C,A,B);
		solve(A,B,C);
		printf("\n");
	}
	return 0;
}

