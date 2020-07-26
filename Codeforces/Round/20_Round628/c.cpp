#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
struct edge{
    int v,id;
};
vector<edge>G[MAXN];
int ans[MAXN];
int du[MAXN];
int now_val;
void bfs(int u){
    int len=G[u].size();
    now_val=0;
    for(int i=0;i<len;++i){
        ans[G[u][i].id]=now_val;
        now_val++;
    }
}

int main(){
    int N;scanf("%d",&N);  
    for(int i=0;i<N-1;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(edge{b,i});
        G[b].push_back(edge{a,i});
        du[a]++;du[b]++;
    }
    int point=-1;
    for(int i=1;i<=N;++i){
        if(du[i]>=3){
            point=i;break;
        }
    }
    if(point==-1){//list
        for(int i=0;i<N-1;++i)printf("%d\n",i);
    }else{
        now_val=0;
        memset(ans,-1,sizeof(ans));
        bfs(point);
        for(int i=0;i<N-1;++i){
            if(ans[i]!=-1);
            else {
                ans[i]=now_val;
                now_val++;
            }
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
