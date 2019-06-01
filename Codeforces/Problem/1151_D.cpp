//tag: greedy,

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
struct node{
    int a,b;
    bool operator<(const node&other)const{
        return b-a<other.b-other.a;
    }
}no[MAXN];

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d%d",&no[i].a,&no[i].b);
    sort(no+1,no+N+1);
    long long ans=0;
    for(int i=1;i<=N;++i){
        ans+=(long long)no[i].a*(i-1)+(long long)no[i].b*(N-i);
    }
    printf("%lld\n",ans);
    return 0;
}

