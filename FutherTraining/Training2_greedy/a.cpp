#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[500];
int main(){
	char s[1007];scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i){
		if(s[i]>='a'&&s[i]<='z')a[s[i]]++;
		else a[s[i]-'A'+'a']++;
	}
	sort(a,a+500);
	int now=26,sum=0;
	for(int i=499;i>=0;--i){
		sum+=a[i]*now;
		now--;
	}
	printf("%d\n",sum);
	return 0;
}
