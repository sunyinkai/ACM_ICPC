#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
const long long INF=1e17+7;
int x[MAXN],c[MAXN];
int cost[MAXN];
int K,N;
long long solve(int id){
 //   printf("id:%d\n",id);
    long long ans=c[id];
    int top=0;
    for(int i=1;i<=N;++i){
        if(i==id)continue;
        cost[top++]=c[i]+abs(x[i]-x[id]);
    }
    nth_element(cost,cost+K,cost+top);
    for(int i=0;i<K;++i){
        ans+=cost[i];
 //       printf("cost[%d]:%d\n",i,cost[i]);
    }
    return ans;
}

int main(){
    int T;scanf("%d",&T);
    for(int test=1;test<=T;++test){
        scanf("%d%d",&K,&N);
        for(int i=1;i<=N;++i)
            scanf("%d",&x[i]);
        for(int i=1;i<=N;++i)
            scanf("%d",&c[i]);
        long long ans=INF;
        for(int i=1;i<=N;++i){
           ans=min(ans, solve(i));
        }
        printf("Case #%d: %lld\n",test,ans);
    }
    return 0;
}
