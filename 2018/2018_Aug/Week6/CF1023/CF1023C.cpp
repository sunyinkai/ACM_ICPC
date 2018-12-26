#include<cstdio>
const int MAXN=2e5+7;
char s[MAXN];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	scanf("%s",s);
	int x=(n-k)/2,y=(n-k)/2;
	for(int i=0;i<n;++i){
		if(s[i]=='('){
			if(x){
				x--;
			}else{
				printf("%c",s[i]);
			}
		}else{
			if(y){
				y--;
			}else{
				printf("%c",s[i]);
			}
		}
	}
	return 0;
}
