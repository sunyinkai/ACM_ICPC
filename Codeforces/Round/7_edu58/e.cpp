#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;scanf("%d",&N);
	int max_x=0,max_y=0;
	while(N--){
		char s[5];int x,y;scanf("%s%d%d",s,&x,&y);
		if(x>y)swap(x,y);
		if(s[0]=='+'){
			max_x=max(max_x,x);
			max_y=max(max_y,y);
		}else{
			if(x>=max_x&&y>=max_y)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
