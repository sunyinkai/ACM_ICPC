#include<stdio.h>
#include<algorithm>
using namespace std;
int n,flag=0;
int a[1000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int i=0,j=n-1;
	for(int i=0;i<n;i++){
		if(a[i]>=0)
			break;
		int j=i+1,k=n-1;
		while(k>j){
			int m = a[k]+a[j];
			if(m>-a[i]){
				k--;
			}
			if(m<-a[i]){
				j++;
			}
			if(m==-a[i]){
				printf("%d %d %d\n",a[i],a[j],a[k]);
				flag=1;
				j++;
				k--;
			} 
		}
	}
	if(flag==0){
		printf("No Solution\n");
	}
}
