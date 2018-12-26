#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

const int N=301000;
const double pi=acos(-1.0);
struct node{
    double x,y;   //x:实部  y:虚部 
    node (double xx=0,double yy=0){
        x=xx;y=yy;
    }
};
node a[N],b[N],omega[N],a_omega[N];
int n,m,fn;

node operator +(const node &a,const node &b){return node(a.x+b.x,a.y+b.y);}
node operator -(const node &a,const node &b){return node(a.x-b.x,a.y-b.y);}
node operator *(const node &a,const node &b){return node (a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}

void init(int n){
    //欧拉公式 w=e^(2*k*pi/n)=(cos(2*k*pi/n),sin(2*k*pi/n)i)
    for (int i=0;i<n;i++){
        omega[i]=node(cos(2.0*i*pi/n),sin(2.0*i*pi/n));
        a_omega[i]=node(cos(2.0*i*pi/n),-sin(2.0*i*pi/n));//
    }
} 

void FFT(int n,node *a,node *w){
    int i,j=0,k;
    for (i=0;i<n;i++){//Rader算法(雷德算法)
        if (i>j) swap(a[i],a[j]);
        for (int l=n>>1;(j^=l)<l;l>>=1);   ///调整为最底层位置
    }

	//如果知道最终状态,自底向上合并可以省下nlogn的空间
    for (i=2;i<=n;i<<=1){   //i:合并的区间长度,自底向上合并
        int m=i>>1;
        for (j=0;j<n;j+=i)
            for (k=0;k<m;k++){
                node z=a[j+k+m]*w[n/i*k];  ///蝴蝶操作
                a[j+m+k]=a[j+k]-z;
                a[j+k]=a[j+k]+z;
            }
    }
}

int main(){
    scanf("%d%d",&n,&m);
	//两个多项式做乘法
    for (int i=0;i<=n;i++) scanf("%lf",&a[i].x);
    for (int i=0;i<=m;i++) scanf("%lf",&b[i].x);
    fn=1;
    while (fn<=n+m) fn<<=1;
    init(fn);  //处理主n次方根 
    FFT(fn,a,omega);   //转成点值表达,dft
    FFT(fn,b,omega);
    for (int i=0;i<=fn;i++)
        a[i]=a[i]*b[i];
    FFT(fn,a,a_omega);  //转成系数表达,idft
    for (int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/fn+0.5));  //最后一定要除以n!!!
    return 0; 
}
