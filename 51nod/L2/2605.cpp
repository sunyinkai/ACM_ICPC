#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int dp[MAXN][2];
vector<int>G[MAXN];
int dfs(int u,int pre,int st){
    if(dp[u][st]!=-1)return dp[u][st];
    if(st==0)dp[u][0]=0;
    else dp[u][1]=a[u];
    for(int i=0;i<G[u].size();++i){
        int v=G[u][i];
        if(v==pre)continue;
        if(st==0){
            dp[u][0]+=max(dfs(v,u,0),dfs(v,u,1));
        }else{
            dp[u][1]+=dfs(v,u,0);
        }
    }
    return dp[u][st];
}

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i)scanf("%d",&a[i]);
    for(int i=1;i<N;++i){
        int x,y;scanf("%d%d",&x,&y);
        G[y].push_back(x);
        G[x].push_back(y);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",max(dfs(1,0,0),dfs(1,0,1)));
    return 0;
}
