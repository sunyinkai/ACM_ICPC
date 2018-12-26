#include <bits/stdc++.h>

using namespace std;

const int maxn=1000005;
bool isprime[maxn];
int miu[maxn];
int prime[maxn];
int cnt;

long long p;

void getmiu()
{
    memset(isprime,0,sizeof(isprime));
    cnt=0;miu[0]=0;miu[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]==0)
        {
            prime[cnt++]=i;
            miu[i]=-1;
        }
        for(int j=0;j<cnt&&prime[j]*i<maxn;j++)
        {
            isprime[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                miu[i*prime[j]]=0;
                break;
            }
            miu[i*prime[j]]=-miu[i];
        }
    }
}

inline long long getmut2(long long a)
{
	__int128 ans=a;
	ans*=a+1;
	ans*=2*a+1;
	ans/=6;
	ans%=p;
    return ans;
}
inline long long getmut3(long long a)
{
	__int128 ans=a;
	ans*=a+1;
	ans/=2;
	ans%=p;
	ans=ans*ans%p;
	return ans;
}


int main()
{
    getmiu();
    long long n;
    while(~scanf("%lld%lld",&n,&p))
    {
        long long tmp=sqrt(n);
        __int128 ans2=0,ans3=0;
        for(long long  i=1;i<=tmp;i++)
        {
            if(miu[i]==0)continue;
            __int128 d=i*i;
            __int128 tt=n/d;
			__int128 t=d*d%p;
			t*=getmut2(tt)%p;
            ans2=((ans2+ miu[i]*t)%p+p)%p;
			__int128 pow3=d*d%p*d%p;
			pow3=pow3*getmut3(tt)%p;
            ans3=((ans3+ miu[i]*pow3 )%p+p)%p;
        }
		
        long long ans=((ans2*(n+1) - ans3)%p+p)%p;
        printf("%lld\n",ans);
    }
    return 0;
}

