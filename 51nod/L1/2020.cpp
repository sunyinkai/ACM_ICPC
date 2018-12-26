#include<cstdio>
#include<algorithm>
using namespace std;
void to_num(int &num,int *a){
	for(int i=0;i<4;++i)
		num=num*10+a[i];
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		int val=n;
		while(k--){
			int a[4],tot=0;
			while(val){a[tot++]=val%10;val/=10;}
			sort(a,a+tot);
			int num0=0;
			to_num(num0,a);

			reverse(a,a+tot);
			int num1=0;
			to_num(num1,a);
			val=num1-num0;
			while(val<=1000)val=val*10;
		}
		printf("%d\n",val);
	}
	return 0;
}
