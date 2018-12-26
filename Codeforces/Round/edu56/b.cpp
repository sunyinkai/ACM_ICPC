#include<bits/stdc++.h>
using namespace std;
const int MAXN=1007;
char s[MAXN];
int cnt[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int len=strlen(s);
		memset(cnt,0,sizeof(cnt));
		int kind=0;
		for(int i=0;i<len;++i){
			cnt[(int)s[i]]++;
			if(cnt[(int)s[i]]==1)++kind;
		}
		bool isok=false;
		if(len==1)isok=true;
		if(kind==1)isok=true;
		sort(s,s+len);
		if(isok)printf("-1\n");
		else printf("%s\n",s);
	}
	return 0;
}
