#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+7;
char s[MAXN];
int N;
void to_decimal(int x,char*s){
	s[0]='\0';
	int len=0;
	while(x){
		s[len++]=x%2+'0';
		s[len]='\0';
		x/=2;
	}
	reverse(s,s+len);
}
bool isok(char *s){
	int ans=0;
	for(int i=0;s[i];++i){
		ans=ans*10+s[i]-'0';
		ans%=N;
	}
	return ans==0;
}
int main(){
	int i;scanf("%d",&N);
	for(i=1;;++i){
		to_decimal(i,s);
		if(isok(s))break;
	}
	printf("%s\n",s);
	return 0;
}
