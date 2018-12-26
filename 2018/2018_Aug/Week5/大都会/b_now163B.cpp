#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
void init(){
	for(int i=2;i<MAXN;++i){
		int sum=1;
		for(int j=2;j*j<=i;++j){
			if(i%j==0){
				sum+=j;
				if(j*j!=i)sum+=i/j;
			}
		}
		a[i]=(i==sum);
	}
}
int main(){
	init();
	int T;scanf("%d",&T);
	init();
	for(int test=1;test<=T;++test){
		int N;scanf("%d",&N);
		printf("Case %d:",test);
		if(a[N]==0)printf(" Not perfect.\n");
		else{
			printf(" %d = %d",N,1);
			int q[100],top=0;
			for(int j=2;j*j<=N;++j){
				if(N%j==0){
					q[top++]=j;
					if(j*j!=N)q[top++]=N/j;
				}
			}
			sort(q,q+top);
			for(int i=0;i<top;++i)
				printf(" + %d",q[i]);
			printf("\n");
		}
	}
	return 0;
}
