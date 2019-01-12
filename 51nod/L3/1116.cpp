#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;

char s[MAXN];
int to_id(char ch){
	int ans;
	if(ch>='0'&&ch<='9') ans=ch-'0';
	else if(ch>='A'&&ch<='Z')ans=10+ch-'A';
	else ans=0 ;
	return ans;
}
bool isok(int base,int len){
	int ans=0,t=1;
	for(int i=len-1;i>=0;--i){
		ans+=t*to_id(s[i]);
		ans%=base-1;
		t=t*base%(base-1);
	}
	return ans==0;
}

int main(){
	scanf("%s",s);
	int len=strlen(s);
	int min_begin=0;
	for(int i=0;i<len;++i)
		min_begin=max(min_begin,to_id(s[i]));
	min_begin+=1;
	min_begin=max(min_begin,2);
	int ans=-1;
	for(int i=min_begin;i<=36;++i)
		if(isok(i,len)){
			ans=i;
			break;
		}
	if(ans==-1)printf("No Solution\n");
	else printf("%d\n",ans);
	return 0;
}

