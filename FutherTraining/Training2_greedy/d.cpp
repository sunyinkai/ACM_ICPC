#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10007;
int a[MAXN];
int visit[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	int res=0;
	for(int i=N-1;i>=0;--i){
		if(visit[i])continue;
		for(int j=i-1;j>=0;--j){
			if(visit[j]||a[i]+a[j]>M)continue;
			else{
				visit[j]=1;
				break;
			}
		}
		++res;
	}
	printf("%d\n",res);
	return 0;
}
