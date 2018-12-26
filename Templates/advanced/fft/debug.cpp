#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n=8;
	int a[100];
	for(int i=0;i<n;++i)a[i]=i;
	int  i=0,j=0;
	for(i=0;i<n;++i){
		if(i>j)swap(a[i],a[j]);
		printf("i=%d,j=%d\n",i,j);
		for(int l=n/2;(j^=l)<l;l/=2);
	}
	for(int i=0;i<n;++i)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
