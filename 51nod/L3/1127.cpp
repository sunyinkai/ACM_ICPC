#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+7;
char s[MAXN];
int mp[MAXN],count=0;
int main(){
	scanf("%s",s);
	int len=strlen(s);
	int i=0,j=0;
	int ans=INF;
	//printf("len=%d\n",len);
	while(i<len&&j<len){
		if(count<26){
			mp[(int)s[j]]++;
			if(mp[(int)s[j]]==1){++count;}
			++j;
		}else{
		//	printf("i=%d,j=%d\n",i,j);
			ans=min(ans,j-i);
			mp[(int)s[i]]--;
			if(mp[(int)s[i]]==0)--count;
			++i;
		}
	}
	if(ans==INF)printf("No Solution\n");
	else printf("%d\n",ans);
	return 0;
}

