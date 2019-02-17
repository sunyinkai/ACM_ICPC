#include<bits/stdc++.h>
using namespace std;
map<long long,int>mp;
const long long INF=1e18+7;

int main(){
	long long N,b;
	scanf("%lld%lld",&N,&b);
	for(long long i=2;i*i<=b;++i){
		while(b%i==0){
			b/=i;
			mp[i]++;
		}
	}
	if(b>1)mp[b]++;
	long long ans=INF;
	for(auto it=mp.begin();it!=mp.end();++it){
		long long cnt=0;
		long long tt=N;
		while(tt){
			cnt+=tt/it->first;
			tt/=it->first;
		}
		ans=min(ans,cnt/it->second);
	}
	printf("%lld\n",ans);
	return 0;
}
