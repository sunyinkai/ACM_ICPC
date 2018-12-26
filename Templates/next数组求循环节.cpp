#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
char s[MAXN];
int next[MAXN];
int main(){ 
	int N;
	int test=1;
	while(~scanf("%d",&N)&&N){ 
		scanf("%s",s);
		int i=0,j=next[0]=-1;
		while(i<N){ 
			while(j!=-1&&s[i]!=s[j])j=next[j];
			next[++i]=++j;
		}


		printf("Test case #%d\n",test++);
		for(int i=1;i<N;++i){ 
			int id=i+1;
			if(id%(id-next[id])==0){ 
				if(id/(id-next[id])==1)continue;
				printf("%d %d\n",id,id/(id-next[id]));
			}
		}
		printf("\n");
	}
	return 0;
}
