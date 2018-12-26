#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int MAXN=1e6+7;
const int INF=1e9+7;
set<int>st;
map<int,int>mp;
int a[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&a[i]);
		st.insert(a[i]);
	}
	int len=st.size();
	st.clear();
	int i=1,j=1;
	int res=INF;
	while(i<=N||j<=N){
		while(i<=N&&(int)st.size()<len){
			mp[a[i]]++;st.insert(a[i]);
			++i;
		}
		if((int)st.size()==len){
	//		printf("i=%d,j=%d\n",i,j);
			res=min(res,i-j);
		}
		mp[a[j]]--;
		if(mp[a[j]]==0)st.erase(a[j]);
		++j;
	}
	printf("%d\n",res);
	return 0;
}
