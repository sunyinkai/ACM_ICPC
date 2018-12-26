//所有区间内最小值之和
#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
long long ans=0;
int a[MAXN];
void solve(int l,int r){
	if(l>r){
		return ;
	}
	int x=-1;
	for(int i=l;i<=r;++i){
		if(x==-1||a[i]<a[x])x=i;
	}
	ans+=((long long)(r-x+1)*(x-l+1))*a[x];
	printf("l=%d,r=%d,len=%d,a[x]=%d\n",l,r,(r-x+1)*(x-l+1),a[x]);
	solve(l,x-1);
	solve(x+1,r);
}

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	solve(1,N);
	printf("%lld\n",ans);
	return 0;
}
