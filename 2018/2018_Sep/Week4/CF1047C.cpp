#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
const int MAXN=1.5e7+7;
int mp[MAXN];
int main(){
	int N;scanf("%d",&N);
	int res=0;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		res=__gcd(res,x);
		for(int i=1;i*i<=x;++i){
			if(x%i==0){
				mp[i]++;
				if(i*i!=x)mp[x/i]++;
			}
		}
	}
	int ans=INF;
	for(auto it=res+1;it<MAXN;++it){
		if(mp[it])ans=min(ans,N-mp[it]);
	}
	if(ans==INF)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
