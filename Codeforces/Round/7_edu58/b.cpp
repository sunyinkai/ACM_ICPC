#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
char s[MAXN];
int isok[MAXN];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int status=0;
	for(int i=0;i<len;++i){
		if(status==0){
			if(s[i]=='['){
				status=1;
				isok[i]=1;
			}
		}
		if(status==1){
			if(s[i]==':'){
				isok[i]=1;
				break;
			}
		}
	}//front
	status=0;
	for(int i=len-1;i>=0;--i){
		if(isok[i])break;
		if(status==0){
			if(s[i]==']')status=1,isok[i]=1;
		}
		if(status==1){
			if(s[i]==':'){
				isok[i]=1;
				break;
			}
		}
	}//back
	int cnt=0;
	for(int i=0;i<len;++i)
		cnt+=isok[i];
	bool hasAns=(cnt==4);
	int ans=4;
	int sum=0;
	for(int i=0;i<len;++i){
		sum+=isok[i];
		if(isok[i])continue;
		if(sum==2){
			if(s[i]=='|')++ans;
		}
	}
	if(hasAns)printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
