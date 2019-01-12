#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+7;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		a[x]++;
	}
	int ans=0;
	for(int i=0;i<MAXN;++i){
		a[i+1]+=a[i]/2;
		ans+=a[i]%2;
	}
	printf("%d\n",ans);
	return 0;
}
