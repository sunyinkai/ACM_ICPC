//考虑到 K<=C(n,2) ?
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=5e4+7;
int a[MAXN];
int N,K;
bool isok(long long x){
    int i=1,j;
    long long cnt=0;
    for(j=1;j<=N;++j)
        if(a[j]<=x)++cnt;
    --j;
    for(;i<j;){
        if(a[i]+a[j]<=x){
            cnt+=j-i;
            ++i;
        }else{
            --j;
        }
    }
    printf("%lld: %lld\n",x,cnt);
    return cnt>=K;
}

int main(){
    scanf("%d%d",&N,&K);
    long long total=0;
    for(int i=1;i<=N;++i){
        scanf("%d",&a[i]);
        total+=a[i];
    }
    sort(a+1,a+N+1);

    long long lo=0,hi=total;
    while(hi-lo>1){
        long long mid=(hi+lo)/2;
        if(isok(mid))hi=mid;
        else lo=mid;
    }
    printf("%lld\n",hi);
    return 0;
}
