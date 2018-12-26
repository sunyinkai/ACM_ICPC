#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
typedef long long ll;
const ll MAXN=3e6+7;
int isprime[MAXN];


void init(){
	memset(isprime,-1,sizeof(isprime));
	isprime[1]=0;
	for(ll i=2;i<MAXN;++i){
		if(isprime[i]){
			for(ll j=2*i;j<MAXN;j+=i)isprime[j]=0;
		}
	}
}

ll cnt[MAXN];

bool  isok(ll l,ll r){
	for(ll i=2;i<=l-1;++i){
		if(isprime[i]){
			ll val=i,num=0;
			bool can=true;
			for(;can;){
				++num;
				can=false;
				ll t=l/val; 
				if((t*val>=l)&&(t*val<=r))can=true;
				if(((t+1)*val>=l)&&((t+1)*val<=r))can=true;
				val*=i;
			}
			num=num-1;
			if(num<cnt[i])return false;
		}
	}
	return true;
}

int main(){
	ll T;scanf("%lld",&T);
	init();
	while(T--){
		ll N;scanf("%lld",&N);
		//求LCM(1...N)
		memset(cnt,0,sizeof(cnt));
		for(ll i=2;i<=N;++i){
			if(isprime[i]){
				ll num=0,val=1;
				while(val<=N){
					val*=i;
					++num;
				}
				cnt[i]=max(0,num-1);
			}
		}

		//求LCM(N+1,M)
		ll lo=N,hi=3*N+5;
		while(hi-lo>1){
			ll mid=(hi+lo)/2;
			if(isok(N+1,mid))hi=mid;
			else lo=mid;
		}
		printf("%lld\n",hi);
	}
	return 0;
}
