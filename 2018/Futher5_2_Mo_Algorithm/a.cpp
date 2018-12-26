#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
long long gcd(long long a,long long b){ 
	return b?gcd(b,a%b):a;
}

int block;
struct node{ 
	int l,r,id;
	bool operator<(const node& other )const{ 
		if(l/block==other.l/block){ 
			return  r<other.r;
		}else{
			return l<other.l;
		}
	}
}no[MAXN];

int N,M;
int a[MAXN];
long long C2(long long x){ 
	return x*(x-1)/2;
}
long long fenzi,cnt;
int num[MAXN];
void add(int x){ 
	++cnt;
	fenzi-=C2(num[x]);
	++num[x];
	fenzi+=C2(num[x]);
}

void remove(int x){ 
	--cnt;
	//printf("remove:prime=%lld\n",fenzi);
	//printf("num[x]=%d\n",num[x]);
	fenzi-=C2(num[x]);
	--num[x];
	//printf("num[x]=%d\n",num[x]);
	fenzi+=C2(num[x]);
	//printf("after remove:fenzi=%lld\n",fenzi);
}


long long x[MAXN],y[MAXN];
void solve(){ 
	memset(num,0,sizeof(num));
	int  L=1,R=1;//当前下标
	num[a[L]]=1;//init注意
	fenzi=0;
	cnt=1;

	for(int i=0;i<M;++i){ 
	//	printf("l=%d,r=%d\n",no[i].l,no[i].r);
		while(L<no[i].l){remove(a[L]);L++;}
	//	printf("fenzi=%lld,L=%d,R=%d\n",fenzi,L,R);
		while(L>no[i].l){ L--;add(a[L]);}
		while(R<no[i].r){ R++;add(a[R]);}
		while(R>no[i].r){ remove(a[R]);R--;}
		long long fenmu=cnt*(cnt-1)/2;
	//	printf("fenzi=%lld,fenmu=%lld,cnt=%lld\n\n",fenzi,fenmu,cnt);
		x[no[i].id]=fenzi,y[no[i].id]=fenmu;
	}

	for(int i=0;i<M;++i){ 
		if(x[i]==0)printf("0/1\n");
		else printf("%lld/%lld\n",x[i]/gcd(x[i],y[i]),y[i]/gcd(x[i],y[i]));
	}
}

int main(){ 
	while(~scanf("%d%d",&N,&M)){ 
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);	
		for(int i=0;i<M;++i){ 
			scanf("%d%d",&no[i].l,&no[i].r);
			no[i].id=i;
		}
		block=sqrt(N);
		sort(no,no+M);
		solve();
	}
	return 0;
}
