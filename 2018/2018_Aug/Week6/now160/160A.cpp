#include<cstdio>
#include<cstring>
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
const int MAXN=107;
int a[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)scanf("%d",&a[i]);
	int res=M;
	for(int i=0;i<N;++i)res=gcd(res,a[i]);
	res%=M;
	if(res==0)printf("1\n");
	else printf("%d\n",M/res);
	return 0;
}
