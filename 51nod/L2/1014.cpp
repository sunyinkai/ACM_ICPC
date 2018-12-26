#include<cstdio>
const int MAXN=1e6+7;
int ans[MAXN],top=0;
int main(){
	int A,P;scanf("%d%d",&P,&A);
	for(int i=1;i<=P;++i){
		long long x=(long long)i*i;
		if(x%P==A)ans[top++]=i;
	}
	if(top==0)printf("No Solution\n");
	else{
		for(int i=0;i<top;++i)
			printf(i==top-1?"%d":"%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
