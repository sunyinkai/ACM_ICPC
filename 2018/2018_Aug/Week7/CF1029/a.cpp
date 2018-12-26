#include<cstdio>
#include<cstring>
const int MAXN=3007;
char t[MAXN];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	char s[MAXN];scanf("%s",s);
	int len=strlen(s);
	memset(t,0,sizeof(t));
	for(int i=0;i<len;++i)t[i]=s[i];
	int ans=0;

	for(int i=0;;++i){
		if(ans==k)break;
		bool isok=true;
		int j;
		for(j=0;j<len;++j){
			if(t[i+j]==0)break;
			if(s[j]!=t[i+j]){isok=false;break;}
		}

		if(isok){
			++ans;
			for(int k=0;k<=len;++k){
				t[i+k]=s[k];
			}
		}
	}
	printf("%s\n",t);
	return 0;
}
