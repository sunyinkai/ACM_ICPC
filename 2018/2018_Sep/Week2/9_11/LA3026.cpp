#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
char s[MAXN];
int next[MAXN];
void getNext(){
	int i=0,j=next[i]=-1;
	int N=strlen(s);
	while(i<N){
		while(j!=-1&&s[i]!=s[j])j=next[j];
		next[++i]=++j;
	}
}
int main(){
	int N;
	int test=1;
	while(~scanf("%d",&N)&&N){
		scanf("%s",s);
		getNext();
		printf("Test case #%d\n",test++);
		for(int i=1;i<=N;++i){
			int x=i-next[i];
			if(i%x==0&&i/x>1){
				printf("%d %d\n",i,i/x);
			}
		}
		printf("\n");
	}
	return 0;
}
