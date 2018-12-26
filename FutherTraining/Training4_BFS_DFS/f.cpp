#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=107;
struct node{
	long long w,v;
	bool operator<(const node&other)const{
		return (v*1.0/w)>(other.v*1.0/other.w);
	}
}a[MAXN];
int N,W;
long long res=0;
void dfs(long long i,long long W,long long val){
	if(i==N){
		res=max(res,val);
		return;
	}
	if(val*1.0+W*1.0*a[i].v*1.0/a[i].w<=res)return;
	if(W>=a[i].w){
		dfs(i+1,W-a[i].w,val+a[i].v);
	}
	dfs(i+1,W,val);
}
int main(){
	while(~scanf("%d%d",&N,&W)){
		for(int i=0;i<N;++i){
			scanf("%lld%lld",&a[i].w,&a[i].v);
		}
		res=0;
		sort(a,a+N);
		dfs(0,W,0);
		printf("%lld\n",res);
	}
	return 0;
}
