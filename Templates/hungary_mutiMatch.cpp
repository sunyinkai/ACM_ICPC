#include<cstdio>
#include <cstring>
const int MAXN=1e5+7;
const int MAXM=12;
using namespace std;
int map[MAXN][MAXM];
int vis[MAXM],link[MAXM][MAXN];
int num[MAXM],cap[MAXM];

//num:已经匹配了的数量,cap:右边的容量
// map:left->right 
//link right->left
//O(VE)
//下标从1开始,

int n,m;
int dfs(int v){
    for(int i=1;i<=m;++i){
        if(map[v][i]&&!vis[i]){
                vis[i]=1;
                if(num[i]<cap[i]){
                    link[i][++num[i]]=v;
                    return 1;
                }
                for(int j=1;j<=num[i];++j){
                    if(dfs(link[i][j])){
                        link[i][j]=v;
                        return 1;
                    }
                }
        }
    }
    return 0;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i)//n->m
            for(int j=1;j<=m;++j)
                scanf("%d",&map[i][j]);
		//下标从1开始
        for(int i=1;i<=m;++i)
            scanf("%d",&cap[i]);
        memset(num,0,sizeof(num));
        int flag=0;

		int res;
        for(int i=1;i<=n;++i){
            memset(vis,0,sizeof(vis));
			res+=dfs(i);//寻找增广路
            /*if(!dfs(i)){
                flag=1;//对于这个题，要求全部匹配,如果找不到直接退出
                break;
            }*/
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
