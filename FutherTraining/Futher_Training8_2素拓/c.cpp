#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int f[MAXN][21];
int query(int a,int b){
	int len=b-a+1;
	int k=0;
	while((1<<(k+1))<=len)++k;
	return __gcd(f[a][k],f[b-(1<<k)+1][k]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d",&f[i][0]);
		for(int k=1;(1<<k)<=N;++k)
			for(int i=1;i+(1<<k)-1<=N;++i)
				f[i][k]=__gcd(f[i][k-1],f[i+(1<<(k-1))][k-1]);
		int Q;scanf("%d",&Q);
		while(Q--){
			int a,b;scanf("%d%d",&a,&b);
		}

	}
	return 0;
}
