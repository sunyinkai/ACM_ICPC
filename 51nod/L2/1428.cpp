//tag: prefix_sum
#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		int l,r;scanf("%d%d",&l,&r);
		mp[l]++;mp[r]--;
	}
	int t=0,ans=0;
	for(auto it=mp.begin();it!=mp.end();++it){
		t+=it->second;
		ans=max(ans,t);
	}
	printf("%d\n",ans);
	return 0;
}
