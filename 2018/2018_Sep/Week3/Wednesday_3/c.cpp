#include<cstdio>
#include<cstring>
const int MAXN=1e4+7;
const int MAXM=1e6+7;
char s[MAXN],t[MAXM];
typedef unsigned long long ull;
ull base=1e9+7;

int main(){
	while(scanf("%s",t)){
		if(strcmp(t,"#")==0)break;
		scanf("%s",s);
		int lenA=strlen(s);
		ull pow=1;
		for(int i=0;i<lenA;++i)pow=pow*base;
		ull A=0,B=0;
		for(int i=0;i<lenA;++i)
			A=A*base+s[i],B=B*base+t[i];
		int lenB=strlen(t);
		int res=0;
		for(int i=0;;++i){
			if(A==B){
				++res;
				i+=lenA-1;
			}
			if(i+lenA>=lenB)break;
			B=B*base+t[i+lenA]-t[i]*pow;
		}
		printf("%d\n",res);
	}
	return 0;
}
