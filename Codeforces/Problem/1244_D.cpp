#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
vector<int>G[MAXN];
int c[4][MAXN];
int du[MAXN];
int x[MAXN],ans_x[MAXN];
const long long INF=1e18+7;
void solve(int now,int pre,int pcol,int ppcol){
    int v=-1;
    for(int i=0;i<G[now].size();++i){
        v=G[now][i];
        if(v==pre)continue;
    }
    if(v==-1)return;

    if(pcol==-1){
        for(int i=1;i<=3;++i){
            solve(v,now,i,pcol);
            x[now]=i;
        }
    }
    else if(ppcol==-1){
        for(int i=1;i<=3;++i){
            if(i!=pcol){
                solve(v,now,i,pcol);
                x[now]=
            }
        }
    }else{
        solve(v,now,6-pcol-ppcol,pcol);
    }

}

int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=3;++i)
        for(int j=1;j<=N;++j)
            scanf("%d",&c[i][j]);
    bool isok=true;
    for(int i=1;i<N;++i){
        int x,y;scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        du[x]++;du[y]++;
        if(du[x]>2 || du[y]>2)isok=false;
    }
    if(!isok){
        printf("-1\n");
        return 0;
    }

    long long ans=INF;//init
    for(int i=1;i<=N;++i){
        if(du[i]==1){
            solve(i,-1,-1,-1);
            break;
        }
    }

    printf("%lld\n",ans);
    for(int i=1;i<=N;++i)
        prinf("%d ",ans_x[i]);
    printf("\n");
}
