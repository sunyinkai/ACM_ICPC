#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,L;scanf("%d%d",&N,&L);
	int min_ans=0,max_ans=0;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		min_ans=max(min_ans,min(x,L-x));
		max_ans=max(max_ans,max(x,L-x));
	}
	printf("%d %d\n",min_ans,max_ans);
	return 0;
}
