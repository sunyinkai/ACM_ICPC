#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
char s[maxn];
ll ol(ll x){
	ll i,res=x;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			res=res-res/i;
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1)
		res=res-res/x;
	return res;
}
ll q(ll x,ll y,ll MOD)
{
	ll res=1;
	while(y)
	{
		if(y%2)
			res=res*x%MOD;
		x=x*x%MOD;
		y/=2;
	}
	return res;
}
long long inv(long long a,long long m){
	if(a==1)return 1;
	return inv(m%a,m)*(m-m/a)%m;
}
int main(void)
{
	ll a,c,i,ans,tmp,b;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		c=1e9+7;
		ans=0;b=0;tmp=ol(c);
		ll len=strlen(s);
		for(i=0;i<len;i++)
			b=(b*10+s[i]-'0')%tmp;
		b+=tmp;
		a=2;
		ans=q(a,b,c);
		printf("%lld\n",ans*inv(2,c)%c);

	}
	return 0;
}


