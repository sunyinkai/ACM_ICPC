#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int visit[MAXN];
int main(){
	int N,K;scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	int res=gcd(a[0],a[0]);
	for(int i=1;i<N;++i)
		res=gcd(res,a[i]);
	res%=K;
	for(int i=1;i<=K;++i)
		visit[(long long)i*res%K]=1;
	int ans=0;
	for(int i=0;i<=K;++i)if(visit[i])++ans;
	printf("%d\n",ans);
	for(int i=0;i<=K;++i)
		if(visit[i])printf("%d ",i);
	return 0;
}
