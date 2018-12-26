#include<iostream>
using namespace std;
void print_int128(__int128 x){
	int a[40],top=0,flag=0;
	if(x<0)x=-x,flag=1;
	while(x){
		a[top++]=x%10;
		x/=10;
	}
	if(flag)printf("-");
	for(int i=top-1;i>=0;--i)printf("%d",a[i]);
	printf("\n");
}
int main(){
	__int128 a=1e12;
	__int128 ans=1;
	for(int i=0;i<10;++i){
		ans=ans*a;
		print_int128(ans);
	}
	return 0;
}
