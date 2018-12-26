#include<bits/stdc++.h>
#define LL long long
#define P pair<int,int>
using namespace std;
const int N = 1e5 + 10;
set<LL> g;
int deg[N];
vector<pair<int,int> > G[N];
int vi[N];
int X[N * 2],Y[N * 2],cnt[N],pos[N];
int main(){
    int  n, m, u, v, Sz;
	int T;scanf("%d",&T);
	for(int i=0;i<T;++i){
		scanf("%d%d",&n,&m);
        Sz = sqrt(m);
        for(int i = 1;i <= n;i++){
            vi[i] = deg[i] = pos[i] = 0;
            G[i].clear();
        }
        g.clear();
        int tot = 0;
        for(int i = 0;i < m;i++){
            scanf("%d%d",&X[i],&Y[i]);
            u = X[i],v = Y[i];
            deg[u]++,deg[v]++;
        }
        for(int i = 0;i < m;i++){
            cnt[i] = 0;
            if(deg[X[i]] < deg[Y[i]]) G[X[i]].push_back(make_pair(Y[i],i));
            else if(deg[Y[i]] < deg[X[i]]) G[Y[i]].push_back(P(X[i],i));
            else{
                if(X[i] < Y[i]) G[X[i]].push_back(P(Y[i],i));
                else G[Y[i]].push_back(P(X[i],i));
            }
        }
        LL ans = 0;
        for(int i = 0;i < m;i++){
            u = X[i],v = Y[i];
            for(auto vp:G[u]) pos[vp.first] = vp.second,vi[vp.first] = i + 1;
            for(auto vp:G[v]){
                int vv = vp.first;
                if(vi[vv] == i + 1){
                    cnt[i]++;
                    cnt[pos[vv]]++;
                    cnt[vp.second]++;
                }
            }
        }
        for(int i = 0;i < m;i++) ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        printf("%lld\n",ans);
    }
    return 0;
}
