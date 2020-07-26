#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int> >mp;
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        int x;scanf("%d",&x);
        mp[x-i].push_back(x);
    }
    long long  ans=0;
    for(auto &it:mp){
        long long val=0;
        for(auto &k:it.second){
           val+=k;
        }
        ans=max(ans,val);
    }
    printf("%lld\n",ans);
    return 0;
}
