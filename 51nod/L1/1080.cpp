#include<cstdio>
//x^2+y^2==N的对数
//双指针
int main(){
	int N;scanf("%d",&N);
	long long i=0,j=1e5;
	bool hasAns=false;
	while(i<=j){
		if(i*i+j*j==N){
			printf("%lld %lld\n",i,j);
			hasAns=true;
			++i;++j;
		}else if(i*i+j*j>N){
			--j;
		}else{
			++i;
		}
	}
	if(!hasAns)printf("No Solution\n");
	return 0;
}
