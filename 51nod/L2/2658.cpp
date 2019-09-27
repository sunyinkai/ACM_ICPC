//tag: hash,logic
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int MAXN=1e5+7;
int a[MAXN],b[MAXN];
int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+N);
    ull up=0,down=0;
    int ans=0;
    for(int i=0;i<N;++i){
        up+=(ull)a[i]*a[i]*a[i];
        down+=(ull)b[i]*b[i]*b[i];
        if(up==down){
            ++ans;
            up=down=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
