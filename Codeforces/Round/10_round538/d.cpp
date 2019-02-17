#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5e3+7;
int a[MAXN];
int q[MAXN],top=0;
int sum[MAXN];
vector<int>G[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%d",&a[i]);
	int prev=a[0],cnt=1;
	for(int i=1;i<N;++i){
		if(a[i]==prev){
			++cnt;
		}else{
			q[++top]=prev;
			G[prev].push_back(top);
			prev=a[i];
			cnt=1;
		}
	}
	q[++top]=prev;
	G[prev].push_back(top);
	for(int i=1;i<MAXN;++i){
		int len=G[i].size();
		if(len<2)continue;
		for(int j=0;j<len;++j)
			for(int k=j+1;k<len;++k){
				//(a,b)  --> [a+1,b-1]
				int a=G[i][j],b=G[i][k];
				sum[a+1]++;sum[b]--;
				printf("%d-- %d\n",a+1,b-1);
			}
	}
	int ans=0,add=0;
	for(int i=0;i<MAXN;++i){
		add+=sum[i];
		ans=max(ans,add);
	}
	printf("%d\n",top-1-ans);
	return 0;
}
