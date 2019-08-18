#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
vector<int>par[MAXN];
vector<int>ans;
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        int x,y;scanf("%d%d",&x,&y);
        par[y].push_back(i);
        if(y==1)ans.push_back(i);
        if(par[y].size()==2){
            ans.push_back(par[y][0]);
            ans.push_back(par[y][1]);
        }
    }
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
