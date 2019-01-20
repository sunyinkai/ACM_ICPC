#include<bits/stdc++.h>
using namespace std;
const int MAXN=20;
int q[MAXN*MAXN];
int done[10000];

int main(){
	int A,B,N;scanf("%d%d%d",&A,&B,&N);
	int top=0;
	q[top++]=1;q[top++]=1;//看做10进制
	done[1*10+1]=1;
	for(;;){
		//找到循环节就退出，
		q[top]=((A*q[top-1]+B*q[top-2])%7+7)%7;
		top++;
		int val=q[top-1]*10+q[top-2];
		if(done[val])break;
		done[val]=1;
	}
	return 0;
}
