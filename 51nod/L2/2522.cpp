//tag: logic,brute_force
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e4+7;
int a[MAXN];
map<int,int>mp;
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&a[i]);
    int K;scanf("%d",&K);

    int sum=0;
    for_each(a+1,a+N+1,[&](int x){
            sum+=x;
            sum=(sum%K+K)%K;
            mp[sum]++;
            });

    long long ans=0;
    for_each(mp.begin(),mp.end(),[&](auto it){
        ans+=(long long)(it.second)*(it.second-1)/2;
        if(it.first==0)ans+=it.second;
    });
    printf("%lld\n",ans);
    return 0;
}
