#include<bits/stdc++.h>
using namespace std;
const int MAXN=1007;
const long long INF=1e9+7;
int a[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	int ans=INF,ans_t=-1;
	for(int t=1;t<=100;++t){
		int tmp=0;
		for(int i=1;i<=N;++i){
			if(a[i]>t){
				tmp+=a[i]-(t+1);
			}else if(a[i]<t){
				tmp+=(t-1)-a[i];
			}
		}
		if(tmp<=ans){
			ans=tmp;
			ans_t=t;
		}
	}
	printf("%d %d\n",ans_t,ans);
	return 0;
}
