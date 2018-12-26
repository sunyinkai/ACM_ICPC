#include<cstdio>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
vector<int>G[MAXN];
unordered_map<long long ,int>mp;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		mp.clear();
		int top=0;
		int N;scanf("%d",&N);
		for(int i=1;i<=N;++i){
			int k;scanf("%d",&k);
			unordered_map<long long ,int >vis;
			while(k--){
				int x,y;scanf("%d%d",&x,&y);
				long long ans=(long long)x*(1e9+7)+y;
				if(vis[ans])continue;
				if(!mp[ans])mp[ans]=++top;
				G[mp[ans]].push_back(i);
				vis[ans]=1;
			}
		}

		int res=0;
		for(int i=1;i<=top;++i){
			int len=G[i].size();
		/*	printf("i=%d\n",i);
			for(int j=0;j<len;++j)
				printf("%d ",G[i][j]);
			printf("\n");*/

			int prev=0;
			for(int j=1;j<len;++j){
				if(G[i][j]-G[i][j-1]==1)continue;
				else{
				//	printf("j=%d,prev=%d\n",j,prev);
					res=max(res,j-prev);
					prev=j;
				}
			}
	//		printf("len=%d,prev=%d\n",len,prev);
			res=max(res,len-prev);
			G[i].clear();
		}
		printf("%d\n",res);
	}
	return 0;
}
