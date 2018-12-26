#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
char a[6][5],b[6][5];
int q[5],top;
vector<char>G[5];
vector<char>res;
int hasAns;
void dfs(int dep,int cnt){
	if(dep==5){
		for(auto it=res.begin();it!=res.end();++it){
			printf("%c",*it);
		}
		printf("\n");
		hasAns=1;
		return;
	}
	int sum=1;
	for(int i=dep+1;i<5;++i)
		sum*=G[i].size();
	int i;
	for( i=0;i<G[dep].size();){
		if(i*sum<=cnt)++i;
		else break;
	}
	i--;
	//printf("dep=%d,G[dep][i]=%c\n",dep,G[dep][i]);
	res.push_back(G[dep][i]);
	dfs(dep+1,cnt-i*sum);
	if(hasAns)return;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int k;scanf("%d",&k);
		for(int i=0;i<6;++i)scanf("%s",a[i]);
		for(int i=0;i<6;++i)scanf("%s",b[i]);
		for(int i=0;i<5;++i)G[i].clear();
		
		for(int i=0;i<5;++i){
			for(int j=0;j<6;++j){
				char s1=a[j][i];
				for(int k=0;k<6;++k){
					if(s1==b[k][i]){
						G[i].push_back(s1);
						break;
					}
				}
			}
		}
		int tmp=1;
		for(int i=0;i<5;++i){//去重
			sort(G[i].begin(),G[i].end());
			G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
			tmp*=G[i].size();
		}
		res.clear();
		if(k>tmp){
			printf("NO\n");
			continue;
		}
		hasAns=0;
		dfs(0,k-1);
	}
	return 0;
}
