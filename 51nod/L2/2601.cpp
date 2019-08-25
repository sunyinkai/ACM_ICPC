//tag: binary_search,hash
#include<cstdio>
#include<unordered_map>

using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+7;
typedef unsigned long long ull;
const ull base=1e9+7;

int a[MAXN],b[MAXN];
int N;
unordered_map<ull,int>mp;

bool isok(int len){
    mp.clear();
    if(len==0)return true;
    ull val=0;
    ull power=1;//base^len
    for(int i=0;i<len;++i){
        val=val*base+a[i];
        power*=base;
    }
    mp[val]=1;
    for(int i=len;i<N;++i){
        val=val*base+a[i]-a[i-len]*power;
        mp[val]=1;
    }

    val=0;
    for(int i=0;i<len;++i)val=val*base+b[i];
    if(mp[val])return true;
    for(int i=len;i<N;++i){
        val=val*base+b[i]-b[i-len]*power;
        if(mp[val])return true;
    }
    return false;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<N;++i){
        scanf("%d",&b[i]);
    }
    
    int lo=0-1,hi=N+1;
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(isok(mid))lo=mid;
        else hi=mid;
    }
    printf("%d\n",lo);
    return 0;
}
