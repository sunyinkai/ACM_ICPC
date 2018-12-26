//将数组赋值一遍,
//前缀和后,求RMQ

#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
long long a[MAXN];
long long f[MAXN][20];
long long query(int l,int r){
	int len=r-l+1;
	int k=0;
	while((1<<(k+1))<=len)++k;
	return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%lld",&a[i]),a[i+N]=a[i];
	N=2*N;
	for(int i=1;i<=N;++i){
		a[i]+=a[i-1];
	}

	for(int i=0;i<=N;++i)f[i][0]=a[i];
	for(int k=1;k<=20;++k){
		for(int i=0;i+(1<<k)-1<=N;++i){
			f[i][k]=min(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		}
	}

	long long ans=0;
	for(int i=1;i<=N;++i){
		ans=max(ans,a[i]-query(max(0,i-N/2),i));
	}

	printf("%lld\n",ans);
	return 0;
}
