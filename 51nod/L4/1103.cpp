#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+7;
int mp[MAXN],a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	int sum=0;
	memset(mp,-1,sizeof(mp));
	mp[0]=0;
	for(int i=1;i<=N;++i){
		sum=(sum+a[i])%N;
		if(~mp[sum]){
			printf("%d\n",i-mp[sum]);
			for(int j=mp[sum]+1;j<=i;++j)
				printf("%d\n",a[j]);
			break;
		}
		mp[sum]=i;
	}
	return 0;
}
