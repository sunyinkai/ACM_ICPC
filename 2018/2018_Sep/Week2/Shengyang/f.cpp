#include<cstdio>
#include <cstring>
const int MAXN=2007;
const int MAXM=2007;

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

int du[MAXN],du2[MAXN];
int main(){
	int k;
	int test=1;
    while(~scanf("%d%d%d",&n,&m,&k)){
		//下标从1开始
		int l,r;scanf("%d%d",&l,&r);
		memset(map,0,sizeof(map));
		memset(du,0,sizeof(du));
		memset(link,0,sizeof(link));
        for(int i=1;i<=m;++i)cap[i]=r;
		for(int i=1;i<=k;++i){
			int a,b;scanf("%d%d",&a,&b);
			map[a][b]=1;
			du[a]++;du2[b++];
		}

		bool hasAns=true;
		for(int i=1;i<=n;++i){
			if(du[i]<l||du2[i]<l){//度数不满足
				hasAns=false;
			}
		}
		printf("Case %d: ",test++);
		if(!hasAns){
			printf("No\n");
			continue;
		}

	    memset(num,0,sizeof(num));
        int flag=0;
        for(int i=1;i<=n;++i){
			for(int j=0;j<l;++j){//找l遍
				memset(vis,0,sizeof(vis));
				if(!dfs(i)){
					flag=1;//对于这个题，要求全部匹配,如果找不到直接退出
					break;
				}
			}
			if(flag)break;
        }
        if(flag)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
