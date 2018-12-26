#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1007;
struct node{
	int cnt,id;
	bool operator<(const node&other)const{
		return cnt<other.cnt;
	}
}a[MAXN];
vector<int>G[MAXN];
int N,ans;
bool solve(){
	sort(a,a+N);
	if(a[0].cnt!=0)return false;
	for(int i=0;i<N;++i){
		if(a[i].cnt==0)continue;
		int num=0;
		for(int j=0;j<i;++j){
			if(a[j].cnt<a[i].cnt){
				G[a[i].id].push_back(a[j].id);
				++num;
				++ans;
			}
			if(num==a[i].cnt)break;
		}
		if(num!=a[i].cnt)return false;
	}
	return true;
}
int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		ans=0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i)G[i].clear();
		for(int i=0;i<N;++i){
			a[i].id=i+1;
			scanf("%d",&a[i].cnt);
		}
		printf("Case #%d: ",test);
		if(solve()){
			printf("Yes\n");
			printf("%d\n",ans);
			for(int i=1;i<=N;++i){
				int len=G[i].size();
				for(int j=0;j<len;++j){
					printf("%d %d\n",i,G[i][j]);
				}
			}
		}else{
			printf("No\n");
		}
	}
	return 0;
}
