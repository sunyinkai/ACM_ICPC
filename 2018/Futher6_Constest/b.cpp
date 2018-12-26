#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<utility>
using namespace std;
const int MAXN=1e5+7;
typedef pair<int,int> P;
vector<int>G[MAXN],idx[MAXN];
int l[MAXN],r[MAXN];
int visit[MAXN];
int ans[MAXN];
int main(){ 
	int T;scanf("%d",&T);
	while(T--){ 
		int N;scanf("%d",&N);
		for(int i=0;i<=N;++i)G[i].clear(),idx[i].clear();
		for(int i=1;i<=N;++i)scanf("%d",&l[i]);
		for(int i=1;i<=N;++i)scanf("%d",&r[i]);
		for(int i=1;i<=N;++i){ 
			G[l[i]].push_back(r[i]);
			idx[l[i]].push_back(i);
		}

		for(int i=1;i<=N;++i)visit[i]=0;

		int res=0;
		int top=0;
		set<P>st;
		st.clear();//P(time,id);
		int now=0;
		while(1){ 
			for(;now<=res;++now){ 
				int len=G[now].size();
				for(int j=0;j<len;++j){ 
					st.insert(P(G[now][j],idx[now][j]));
				}
			}//add

			if(st.empty())break;
			for(;!st.empty();){ 
				set<P>::iterator p=st.begin();
				if(p->first>=res){
					ans[top++]=p->second;
					visit[p->second]=1;
					++res;
					st.erase(p);
					break;
				}else{ 
					st.erase(p);
				}
			}
		}
		printf("%d\n",top);
		for(int i=1;i<=N;++i){ 
			if(!visit[i])ans[top++]=i;
		}
		for(int i=0;i<top;++i){ 
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
