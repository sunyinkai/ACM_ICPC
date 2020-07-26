//tag: DAG,dfs
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=2e5+7;
int w[MAXN];
int du[MAXN];
int val[MAXN];
vector<int>G[MAXN];
int dfs(int u){
    int len=G[u].size();
    int res=0;
    for(int i=0;i<len;++i){
        int v=G[u][i];
        res=max(res,dfs(v));
    }
    return w[u]+res;
}

int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)
        scanf("%d",&w[i]);
    for(int i=0;i<M;++i){
        int a,b;scanf("%d%d",&a,&b);
        G[b].push_back(a);
        du[a]++;
    }
    int ans=0;
    for(int i=1;i<=N;++i){
        if(du[i]==0){
            ans=max(ans,dfs(i));
        }
    }
    printf("%d\n",ans);
    return 0;
}
