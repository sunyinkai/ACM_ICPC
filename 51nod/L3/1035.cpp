#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;scanf("%d",&N);
	int len=0,ans=0;
	for(int num=1;num<=N;++num){
		int t=num;
		while(t%2==0)t/=2;
		while(t%5==0)t/=5;
		if(t==1){
			if(len!=0)continue;
			else{
				ans=num;
			}
			continue;
		}

		int tmp=1,val=10%t;
		while(1){
			if(val==1)break;
			val=val*10%t;
			++tmp;
		}
		if(tmp>=len){
			if(tmp>len)len=tmp,ans=num;
			else ans=num;
		}
	}
	printf("%d\n",ans);
	return 0;
}
