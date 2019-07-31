//tag: logic,list,DAG
#include<cstdio>
#include<unordered_map>
using namespace std;

unordered_map<long long,int>mp;
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        long long x;scanf("%lld",&x);
        mp[x]++;
    }
    bool isok=true;
    int edge=0;
    for(auto it:mp){
        int cnt=it.second;
        if(cnt>=2)isok=false;

        long long val=it.first;
        if(mp.count(val*2))++edge;
        if(val%3==0){
            if(mp.count(val/3))++edge;
        }
    }
    if(edge!=N-1)isok=false;
    printf(isok?"Possible\n":"Impossible\n");
    return 0;
}
