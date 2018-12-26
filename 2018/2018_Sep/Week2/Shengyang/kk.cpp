#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20;
int q[MAXN]={
	1,2,3,5,7,
	11,13,17,23,31,37,
	53,71,73,113,131,
	137,173,311,317
};

int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		char s[107];scanf("%s",s);
		int len=strlen(s);

		printf("Case #%d: ",test);
		if(len>=4){
			printf("317\n");
		}else{
			int num=0;
			for(int i=0;i<len;++i){
				num=num*10+s[i]-'0';
			}
			if(num>=317)printf("%d\n",317);
			else{
				printf("%d\n",q[upper_bound(q,q+MAXN,num)-q-1]);
			}
		}
	}

	return 0;
}
