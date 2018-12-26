#include<cstdio>
int strcmp(char *s,char *t){ 
	int i;
	int cnt=1;
	for(i=0;s[i]==t[i];++i){ 
		++cnt;
		if(s[i]=='\0')return cnt;
		++cnt;
	}
	return cnt;
}
int main(){ 
	printf("%d\n",strcmp("a","a"));
}
