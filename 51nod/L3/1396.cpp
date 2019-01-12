#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+7;
int sum[MAXN];
char s[MAXN];

int main(){
	scanf("%s",s);
	int len=strlen(s);
	int sum=0;
	for(int i=0;i<len;++i)
		sum+=s[i]-'0';
	printf("%d\n",sum);
	return 0;
}
