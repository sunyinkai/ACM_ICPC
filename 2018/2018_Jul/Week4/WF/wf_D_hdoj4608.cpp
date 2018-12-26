#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
char s[MAXN];
void add(char *s,int &len){
	for(int i=0;i<len;++i)s[i]=s[i]-'0';
	reverse(s,s+len);
	s[0]++;
	s[len]=0;
	for(int i=0;i<=len;++i){
		if(s[i]>=10){
			s[i]-=10;
			s[i+1]++;
		}
	}
	if(s[len]!=0)++len;
	reverse(s,s+len);
	for(int i=0;i<len;++i)s[i]=s[i]+'0';
	//printf("%s\n",s);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int len=strlen(s);
		while(1){
			add(s,len);
			int sum=0;
			for(int i=0;i<len;++i)
				sum+=s[i]-'0';
			if(sum%10==0)break;
		}
		printf("%s\n",s);
	}
}
