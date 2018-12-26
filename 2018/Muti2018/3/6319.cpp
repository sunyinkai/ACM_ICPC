#include<cstdio>
#include<cstring>
typedef long long LL;
const int MAXN=1e7+7;
LL a[MAXN],q[MAXN];
int id[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL n,m,k,p,qq,r,MOD;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&m,&k,&p,&qq,&r,&MOD);
		for(int i=1;i<=k;++i)scanf("%lld",&a[i]);
		for(int i=k+1;i<=n;++i)a[i]=(p*a[i-1]+qq*i+r)%MOD;//generate
		long long A=0,B=0;
		int front=0,back=0;
		for(int i=n;i>=n-m+1;--i){
			while(front!=back&&a[i]>q[front-1])front--;
			q[front]=a[i];id[front++]=i;
		}
		A+=q[back]^(n-m+1);B+=(front-back)^(n-m+1);

		for(int i=n-m;i>=1;--i){
			if(i+m-1<id[back])++back;
			while(front!=back&&a[i]>=q[front-1])front--;
			q[front]=a[i];id[front++]=i;
			A+=q[back]^i;B+=(front-back)^i;
		}
		printf("%lld %lld\n",A,B);
	}
	return 0;
}
