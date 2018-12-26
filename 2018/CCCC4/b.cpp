#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+7;
char s[MAXN],t[MAXN];
int main(){
	scanf("%s%s",s,t);
	int lenS=strlen(s);
	int lenT=strlen(t);
	int i=0,j=0;
	while(i<lenS&&j<lenT){
		while(t[j]!=s[i])++j;
		++i;++j;
	}
	int begin=j-1;
	if(i!=lenS){
		printf("0\n");
		return 0;
	}
	
	reverse(s,s+lenS);
	reverse(t,t+lenT);
	i=0,j=0;
	while(i<lenS&&j<lenT){
		while(t[j]!=s[i])++j;
		++i;++j;
	}
	int end=j-1;
	if(i!=lenS){
		printf("0\n");
		return 0;
	}
	//printf("begin=%d,end=%d,lenT=%d\n",begin,end,lenT);
	if(begin+end<lenT){
		printf("%d\n",lenT-begin-end-1);
	}else{
		printf("0\n");
	}
	return 0;
}
