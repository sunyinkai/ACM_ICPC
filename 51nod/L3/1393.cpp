#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
const int MAXN=1e6+7;
char s[MAXN];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	int sum=0;
	int ans=0;
	mp[0]=-1;
	for(int i=1;i<=len;++i){
		if(s[i]=='0')sum+=-1;
		else sum+=1;
		if(!mp[sum])mp[sum]=i;
		else {
			int tag= (sum==0);
			ans=max(ans,i-mp[sum]-tag); 
		}
	}
	printf("%d\n",ans);
	return 0;
}
