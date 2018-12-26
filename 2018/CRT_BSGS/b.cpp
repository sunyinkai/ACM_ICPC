#include<cstdio>
#include<cstring>
#include<cstdlib>

typedef long long LL;
LL extend_gcd(LL a,LL b,LL &x,LL &y){ 
	if(a==0&&b==0)return -1;
	if(b==0){ x=1;y=0;return a;}
	LL d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

LL m[10],a[10];
bool solve(LL &m0,LL &a0,int m,int a){ 
	LL y,x;
	LL g=extend_gcd(m0,m,x,y);
	if(abs(a-a0)%g)return false;
	x*=(a-a0)/g;
	x%=m/g;
	a0=(x*m0+a0);
	m0*=m/g;
	a0%=m0;
	if(a0<0)a0+=m0;
	return true;
}

bool MLES(LL &m0,LL &a0,int n){ 
	bool flag=true;
	m0=1;
	a0=0;
	for(int i=0;i<n;++i)
		if(!solve(m0,a0,m[i],a[i])){ 
			flag=false;
			break;
		}
	return flag;
}

int main(){ 
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){ 
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i)scanf("%lld",&m[i]);
		for(int i=0;i<N;++i)scanf("%lld",&a[i]);
		LL a0,m0;
		printf("Case %d:",test);
		if(MLES(m0,a0,N)){ 
			if(a0==0)a0+=m0;
			printf(" %lld\n",a0);
		}else{ 
			printf(" -1\n");
		}
	}
	return 0;
}
