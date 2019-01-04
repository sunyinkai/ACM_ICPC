#include<bits/stdc++.h>
using namespace std;
const int MAXN=207;
int top=0;
int q[MAXN];

void solve(int x,int y){//x<=y
	int isok=1;
	if((x+y-1)%2!=0)isok=0;
	if((y-x+1)%2!=0)isok=0;

	if(isok)q[top++]=(y-x+1)/2;
}

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i*i<=2*N;++i){
		if(2*N%i==0){
			solve(i,2*N/i);
		}
	}

	if(top-1==0)printf("No Solution\n");
	else{
		sort(q,q+top);
		for(int i=0;i<top-1;++i)printf("%d\n",q[i]);
	}
	return 0;
}
