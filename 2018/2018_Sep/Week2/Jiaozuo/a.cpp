#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		char s[22];scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;++i)s[i]=tolower(s[i]);
		if(strcmp(s,"jessie")==0)printf("Good guy!\n");
		else printf("Dare you say that again?\n");
	}
	return 0;
}
