#include<iostream>
using namespace std;
void print_int128(__int128 x){//output int128
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
__int128 input_int128(){//input int128
	__int128 ans=0;
	char ch;
	while(1){
		ch=getchar();
		if(ch>='0'&&ch<='9')break;
	}
	ans=ch-'0';
	while((ch=getchar())>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
	}
	return ans;
}

int main(){
	__int128 ans,a,b;
	a=input_int128();
	b=input_int128();
	ans=a+b;
	print_int128(ans);
	return 0;
}
