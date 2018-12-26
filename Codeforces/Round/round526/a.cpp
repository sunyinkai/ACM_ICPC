#include<cstdio>
#include<cstdlib>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
const int MAXN=107;
const int INF=1e9+7;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	int ans=INF;
	for(int x=1;x<=N;++x){
		int t=0;
		for(int i=1;i<=N;++i){
			int cost=abs(max(i,x)-1)*4*a[i];
			t+=cost;
		}
		ans=min(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}
