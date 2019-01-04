#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
char s[MAXN];
int a[500];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i){
		if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
		a[s[i]]++;
	}
	sort(a,a+500);
	reverse(a,a+500);
	int ans=0;
	for(int i=0;i<26;++i)
		ans+=a[i]*(26-i);
	printf("%d\n",ans);
	return 0;
}
