#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=507;
int A[MAXN][MAXN];
int Rank(int m,int n){//m equation,n varibles
	int i=0,j=0,k,r,u;
	while(i<m&&j<n){
		r=i;
		for(int k=i;k<m;++k)
			if(A[k][j]){r=k;break;}
		if(A[r][j]){
			if(r!=i)for(int k=0;k<n;++k)swap(A[r][k],A[i][k]);
			for(u=i+1;u<m;++u)if(A[u][j])
				for(k=i;k<=n;++k)A[u][k]^=A[i][k];
			++i;
		}
		++j;
	}
	return i;
}
int isPrime[MAXN],p[MAXN],tot=0;
void  init(){
	memset(isPrime,0,sizeof(isPrime));
	isPrime[0]=isPrime[1]=-1;
	for(int i=2;i<500;++i){
		if(isPrime[i]!=-1){
			p[tot]=i;
			isPrime[i]=tot++;
			for(int j=2*i;j<500;j+=i)isPrime[j]=-1;
		}
	}
	/*for(int i=0;i<tot;++i){
		printf("p[%d]=%d\n",i,p[i]);
	}*/
}
int main(){
	init();
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int k=0;k<n;++k){//变量数
			long long x;scanf("%lld",&x);
			for(int i=0;i<tot;++i){//m方程数
				int cnt=0;
				while(x%p[i]==0&&x){
					++cnt;
					x/=p[i];
				}
				A[i][k]=cnt%2;
			}
		}
		int r=Rank(tot,n);
		printf("%lld\n",((long long)1<<(n-r))-1);
	}
	return 0;
}
