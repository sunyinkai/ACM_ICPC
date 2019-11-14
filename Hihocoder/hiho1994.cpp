#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+7;
vector<int>G[MAXN];
queue<int>q;
int in[MAXN];
int size[MAXN];

int main(){
    int N,M;scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i){
        int x;scanf("%d",&x);
        if(x==0)continue;
        G[i].push_back(x);
        in[x]++;
    }
    for(int i=1;i<=N;++i){
        if(in[i]==0)q.push(i);
    }
    int days=1;
    int total=N;
    size[days++]=total;
    while(!q.empty()){
        int len=q.size();
        total-=len;
        for(int i=0;i<len;++i){
            int u=q.front();q.pop();
            for(int j=0;j<G[u].size();j++){
                int v=G[u][j];
                in[v]--;
                if(in[v]==0)q.push(v);
            }
            G[u].clear();
        }
        size[days++]=total;
    }
    reverse(size+1,size+days);
    for(int i=1;i<days;++i)
        printf("day:%d,size:%d\n",i,size[i]);
    while(M--){
        int x;scanf("%d",&x);
        int id=lower_bound(size+1,size+days,x)-size;
        printf("id:%d\n",id);
    }
    return 0;
}
