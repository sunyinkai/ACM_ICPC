#include<bits/stdc++.h>
using namespace std;
const int MAXM=1e6+7;
int cnt[MAXM];
int main(){
	int N;scanf("%d",&N);
	while(N--){
		int x;scanf("%d",&x);
		for(int i=1;i*i<=x;++i){
			if(x%i==0){
				cnt[i]++;
				if(x/i!=i)cnt[x/i]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<MAXM;++i)
		if(cnt[i]>=2)ans=max(ans,i);
	printf("%d\n",ans);
	return 0;
}
