#include<cstdio>
#include<unordered_map>
using namespace std;
const int MAXN=1e4+7;
long long sum[MAXN];
int a[MAXN];
unordered_map<long long,int>mp;
int main(){
	long long N,K;scanf("%lld%lld",&N,&K);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=N;i>=1;--i)
		sum[i]=sum[i+1]+a[i];
	int ans_left=10007,ans_right=100007;
	mp[0]=N+1;
	for(int i=N;i>=1;--i){
		mp[sum[i]]=i;
		long long val=sum[i]-K;
		if(mp[val])ans_left=i,ans_right=mp[val];
	}
	if(ans_left==10007)printf("No Solution\n");
	else printf("%d %d\n",ans_left,ans_right-1);
	return 0;
}

