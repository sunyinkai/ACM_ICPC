#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
const long long INF=1e13+7;
const int MAXN=2e6+7;

inline long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

map<long long,int>mp;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		long long a,b,c,d,v,t;
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		long long period=a/gcd(a,c)*c;

		mp.clear();
		for(long long i=0;i<period;i+=c) mp[i]+=d;
		long long ans=0;

		long long res=0;//一段的答案
		long long  prev=-INF;
		for(auto it=mp.begin();it!=mp.end();++it){
			long long val=it->first;
			int cnt=it->second;
			if(val-prev<=v)res+=cnt;
			else res+=cnt-1;
			prev=val;
		}
		long long segCnt=t/period;
		ans+=(long long)segCnt*res;   //段内
		//独立的段
		long long val=min(a,c);
		long long tmp=segCnt+1;
		if(t%period==0)tmp--;
		ans+=tmp*((val<=v)*mp[val]);//段与段之间
		ans+=(b+d)-1;//0号位置

		//最后一段
		long long begin=segCnt*period;
		mp.clear();
		for(long long i=begin+a;i<=t;i+=a)mp[i]+=b;
		for(long long i=begin+c;i<=t;i+=c)mp[i]+=d;

		prev=-INF;
		for(auto it=mp.begin();it!=mp.end();++it){
			long long val=it->first;
			int cnt=it->second;
			if(val-prev<=v)ans+=cnt;
			else ans+=cnt-1;
			prev=val;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
