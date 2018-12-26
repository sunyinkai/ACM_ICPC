#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	char s[11];scanf("%s",s);
	int len=strlen(s);
	int a[10];
	for(int i=0;i<len;++i)a[i]=s[i]-'0';
	sort(a,a+len);
	for(int i=0;i<len;++i)printf("%d",a[i]);printf("\n");
	while(1){
		int i,pos;
		for(i=len-2;i>=0;--i){
			if(a[i]<a[i+1]){
				pos=i;
				break;
			}
		}
		if(i==-1)break;
		int minPos=-1;
		for(int i=pos;i<len;++i){
			if(a[i]>a[pos]){
				if(minPos==-1||a[i]<a[minPos])minPos=i;
			}
		}
		swap(a[pos],a[minPos]);
		reverse(a+pos+1,a+len);
		for(int i=0;i<len;++i)printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
