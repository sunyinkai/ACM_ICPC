//tag: dp,prefix_sum
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
struct node{
    int s,e;
}no[MAXN];
int f[MAXN*10];
vector<int>G[MAXN*10];

int main(){
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d%d",&no[i].s,&no[i].e);
        G[no[i].e].push_back(i);
    }
    for(int i=1;i<=MAXN*10;++i){
        int len=G[i].size();
        if(len){
            for(int j=0;j<len;++j){
                int id=G[i][j];
                f[i]=max(f[i],f[no[id].s-1]+(i-no[id].s+1));
            }
        }
        f[i]=max(f[i],f[i-1]);
    }
    printf("%d\n",f[MAXN*10-1]*100);
    return 0;
}
