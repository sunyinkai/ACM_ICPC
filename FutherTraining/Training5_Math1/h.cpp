#include<cstdio>
#include<cstring>
char s[200];
int main(){
	while(~scanf("%s",s)){
		int len=strlen(s);
		int sum0=0,val=0;
		for(int i=0;i<len;++i){
			if(s[i]=='0'){
				sum0++;
				if(s[(i+1)%len]=='0')++val;
			}
		}
		if(val*len>sum0*sum0){
			printf("SHOOT\n");
		}else if(val*len==sum0*sum0){
			printf("EQUAL\n");
		}else{
			printf("ROTATE\n");
		}
	}
	return 0;
}
