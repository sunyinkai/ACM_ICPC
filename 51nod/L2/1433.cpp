#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;scanf("%d",&N);
	int cnt_5=0,cnt_0=0;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		if(x==5)cnt_5++;
		else cnt_0++;
	}
	if(cnt_0==0)printf("-1\n");
	else{
		int x=cnt_5/9*9;
		if(x==0)printf("0\n");
		else{
			while(x--)printf("5");
			while(cnt_0--)printf("0");
			printf("\n");
		}
	}
	return 0;
}
