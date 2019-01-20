#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
char  a[MAXN];
vector<int>G[26];
int N,K;
int main(){
	scanf("%d%d",&N,&K);
	scanf("%s",a);
	int prev=a[0],cnt=1;
	for(int i=1;i<N;++i){
		if(a[i]==prev){
			++cnt;
		}else{
			G[prev-'a'].push_back(cnt);
			prev=a[i];
			cnt=1;
		}
	}
	G[prev-'a'].push_back(cnt);
	int ans=0;
	for(int i=0;i<26;++i){
		int cnt=0;
		int len=G[i].size();
		for(int j=0;j<len;++j){
			cnt+=G[i][j]/K;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
