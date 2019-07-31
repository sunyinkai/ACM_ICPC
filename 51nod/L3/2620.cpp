#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)scanf("%d",&a[i]);
    long long ans=0;
    for(int i=1;i<=N-1;++i){
        ans+=max(a[i],a[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}
