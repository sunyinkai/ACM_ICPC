#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	char s[15];scanf("%s",s);
	int len=strlen(s);
	sort(s,s+len);
	do{
		printf("%s\n",s);
	}while(next_permutation(s,s+len));
	return 0;
}
