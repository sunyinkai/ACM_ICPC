#include<cstdio>
#define min(a,b) (a<b?a:b)
const int INF=1e9+7;
int cnt[32];
int main(){
	long long N,X;scanf("%lld%lld",&N,&X);
	for(int i=0;i<N;++i){
		long long t;scanf("%lld",&t);
		bool isok=true;
		if(t>X)continue;

		for(int j=0;j<31;++j){
			if(X&((long long)1<<j));
			else if(t&((long long)1<<j))isok=false;
		}
		if(!isok)continue;

		for(int j=0;j<31;++j){
			cnt[j]+=t%2;
			t/=2;
		}
	}
	int ans=INF;
	for(int i=0;i<31;++i)
		if(X&((long long)1<<i))ans=min(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}
