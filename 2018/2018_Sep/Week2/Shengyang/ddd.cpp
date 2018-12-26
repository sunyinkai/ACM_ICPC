#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int YYYYYY=1005;

struct XXXXXX{
    int u,v,cost;
};
vector<XXXXXX> edges;
vector<int> G[YYYYYY];
vector<XXXXXX> O_edges;
vector<int> O_G[YYYYYY];
int S,T,K;
struct node{
    int u;
    int f,g;
    bool operator <(const node& rhs)const{
        return f>rhs.f;
    }
};
int h[YYYYYY];
void dij(int t)
{
    priority_queue<node> Q;
    CL(h,-1);
    Q.push((node){t,0,0});
    while(!Q.empty())
    {
        node tmp=Q.top();
        Q.pop();
        int u=tmp.u;
        int cost=tmp.f;
        if(h[u]!=-1)continue;
        h[u]=cost;
        for(int i=0;i<O_G[u].size();i++)
        {
            int mm=O_G[u][i];
            XXXXXX e=O_edges[mm];
            tmp.u=e.v;
            tmp.f=e.cost+cost;
            Q.push(tmp);
        }
    }
}
int cnt[YYYYYY];
int a_star()
{
    CL(cnt,0);
    priority_queue<node> Q;
    if(h[S]==-1)return -1;
    Q.push((node){S,h[S],0});
    node t,tt;
    while(!Q.empty())
    {
        t=Q.top();
        Q.pop();
        int u=t.u;
        int f=t.f;
        int g=t.g;
        cnt[u]++;
        if(cnt[T]==K)return g;
        if(cnt[u]>K)continue;
        for(int i=0;i<G[u].size();i++)
        {
            XXXXXX e=edges[G[u][i]];
            tt.u=e.v;
            tt.g=g+e.cost;
            tt.f=tt.g+h[tt.u];
            Q.push(tt);
        }
    }
    return -1;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        REP(i,0,n){
            G[i].clear();
            O_G[i].clear();
        }
        edges.clear();
        O_edges.clear();
		int len;
        scanf("%d%d%d%d",&S,&T,&K,&len);
        int a,b,c;
        REP(i,1,m)
        {
            scanf("%d%d%d",&a,&b,&c);
            edges.push_back((XXXXXX){a,b,c});
            O_edges.push_back((XXXXXX){b,a,c});
            int mm=edges.size();
            G[a].push_back(mm-1);
            O_G[b].push_back(mm-1);
        }
        dij(T);
        int ans=a_star();
		//printf("%d\n",ans);
		if(ans==-1){
			printf("Whitesnake!\n");
			continue;
		}
		if(ans<=len){
			printf("yareyaredawa\n");
		}else{
			printf("Whitesnake!\n");
		}
    }
    return 0;
}
