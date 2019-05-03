//tag: logic,sort,prefix_sum
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
const int INF=1e9+7;

struct node{
    int val,id;
    bool operator<(const node&other)const{
        return val<other.val;
    }
}no[MAXN];
int f[MAXN],g[MAXN];

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&no[i].val);
        no[i].id=i;
    }
    sort(no+1,no+N+1);
    int ans=0;
    g[N+1]=INF;
    for(int i=N;i>=1;--i){
        g[i]=INF;
        f[i]=max(no[i].id,f[i+1]);
        g[i]=min(no[i].id,g[i+1]);
    }
    for(int i=1;i<=N;++i){
        ans=max(ans,(f[i]-no[i].id)*no[i].val);
        ans=max(ans,(no[i].id-g[i])*no[i].val);
    }
    printf("%d\n",ans);
    return 0;
}
