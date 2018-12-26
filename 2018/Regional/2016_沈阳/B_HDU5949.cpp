#include<cstdio>
#include<cstring>
int main(){
	int N;scanf("%d",&N);
	while(N--){
		char s[100];scanf("%s",s);
		int len=strlen(s);
		int res=0;
		for(int i=0;i<len;++i){
			if(s[i]=='H')res++;
			if(s[i]=='C')res+=12;
			if(s[i]=='O')res+=16;
		}
		printf("%d\n",res);
	}
	return 0;
}
