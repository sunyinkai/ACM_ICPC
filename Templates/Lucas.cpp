//C(m,n)%p
//m,n<=1e18,p<=1e5
#include<bits/stdc++.h>  
using namespace std;  
typedef long long ll;  
const int N =120000;  
ll n, m, p, fac[N];  
void init(){  
    fac[0] =1;  
    for(int i =1; i <= n; i++)  
        fac[i]=fac[i-1]*i % p;  
}  
ll q_pow(ll a, ll b) {
    ll  ans =1;  
    while(b){  
        if(b &1)  ans = ans * a % p;  
        b>>=1;  
        a = a*a % p;     
    }  
    return ans;  
}  
ll C(ll n, ll m){  
    if(m > n)return 0;  
    return  fac[n]*q_pow(fac[m]*fac[n-m], p-2) % p;  
}  
ll Lucas(ll n, ll m ){
	return m==0?1:(C(n%p, m%p)*Lucas(n/p, m/p))%p;
}  
int main(){  
    scanf("%lld%lld%lld", &n, &m, &p);//C(n,m)%p p为素数
    init();  
    printf("%lld\n", Lucas(n, m));  
    return 0;  
}  
