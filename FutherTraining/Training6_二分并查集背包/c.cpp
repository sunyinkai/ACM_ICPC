#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4007;
int A[MAXN],B[MAXN],C[MAXN],D[MAXN];
int AA[MAXN*MAXN],BB[MAXN*MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)){
		for(int i=0;i<N;++i)scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				AA[i*N+j]=A[i]+B[j];
				BB[i*N+j]=C[i]+D[j];
			}
		sort(AA,AA+N*N);
		sort(BB,BB+N*N);
		long long res=0;
		for(int i=0;i<N*N;++i){
			int val=AA[i];
			res+=upper_bound(BB,BB+N*N,-val)-lower_bound(BB,BB+N*N,-val);
		}
		printf("%lld\n",res);
	}
	return 0;
}
