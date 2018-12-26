#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define CLR(a,b) memset((a),(b),sizeof((a)))
typedef long long ll;
const int N = 5000000;
bool check[N+10];
int prime[N+10];
int mu[N+10];
ll mu_sum[N+10];
long long ans;
inline void Moblus(){
    CLR(check, false);
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= N; i++){
        if( !check[i] ){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot && i*prime[j] <= N; j++){
            check[i * prime[j]] = true;
            if( i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    for(int i = 1; i <= N; ++i)
        mu_sum[i] = mu_sum[i-1] + mu[i];
}
unordered_map<ll,ll> mp;
inline ll Mertens(ll n){
    if(n <= N) return mu_sum[n];
    if(mp.count(n)) return mp[n];
    ll ans = 1, ed;
    for(ll i = 2; i <= n; i = ed+1){
        ed = n/(n/i);
        ans -= (ed - i + 1)*Mertens(n/i);
    }
    return mp[n] = ans;
}
/*
long long getans(long long a,long long p)
{
    if(a<p)return Mertens(a);
    else return  Mertens(a) + Mertens(a/p)+ ;
}
*/
inline long long getans(long long a,long long p,int fl)
{
    long long cc=Mertens(a);
    a/=p;
    while(a>0)
    {
        cc+=fl*Mertens(a);
        a/=p;
    }
    return cc;
}

long long pri[30];
int cnt=0;
inline int getpri(long long n)
{
    int flag=0;
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0)
        {
            pri[cnt]=i;
            cnt++;
            if(n%(i*i)==0){flag=1;break;}
            n/=i;
        }
    }
    if(n>1)pri[cnt]=n;cnt++;
    return flag;
}
inline void solve(long long m,int x)
{
    long long tmp=1;
    int cntbit=0;
    for(int i=0;i<cnt;i++)
        if(x&(1<<i))
        {
            tmp*=pri[i];
            cntbit++;
        }
      //  long long tmmp;
    if(cntbit&1)ans+=getans(m,tmp,1);
    else ans-=getans(m,tmp,-1);
   // ans+=tmmp
   // printf("%lld %lld %lld\n",m,tmp,tmmp);

}



int main(){
    Moblus();
    ll m,n;
    scanf("%lld%lld", &m, &n);
    if(getpri(n)==1)printf("0\n");
    else
    {
        ans=0;
        int all=1<<cnt;
        for(int i=1;i<all;i++)
            solve(m,i);
        printf("%lld",-ans);
    }

    return 0;
}

