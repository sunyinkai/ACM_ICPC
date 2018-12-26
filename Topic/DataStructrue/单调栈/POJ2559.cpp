#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=1e5+7;
int a[MAXN];
int stack[MAXN],top=0;
int left[MAXN],right[MAXN];
int main(){
	int N;
	while(scanf("%d",&N)&&N){

		long long res=0;
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		top=0;
		for(int i=0;i<N;++i){
			if(top==0){//栈为空
				stack[top++]=i;
				left[i]=i;
			}else if(a[i]>=a[ stack[top-1] ]){//满足单调性
				left[i]=left[ stack[top-1] ];
				stack[top++]=i;
			}else{
				while(top!=0&&a[i]<stack[top-1]){
					right[ stack[top-1] ]=stack[top-1];
					int no=stack[--top];
					res=max(res,(right[no]-left[no])*a[no]);
					
				}
				if(top==0)left[i]=i;
				else left[i]=left[ stack[top-1] ];
				stack[top++]=i;
			}
		}
		while(top!=0){
		
		}
		for(int i=0;i<N;++i){
			printf("left[%d]=%d,right[%d]=%d\n",i,left[i],i,right[i]);
		}
		printf("%lld\n",res);
	}

	return 0;
}
