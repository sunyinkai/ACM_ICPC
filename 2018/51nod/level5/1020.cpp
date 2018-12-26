#include<bits/stdc++.h>
using namespace std;
int main(){
	const int N=2;
	int a[N]={1,2};
	int cnt[100000];
	memset(cnt,0,sizeof(cnt));
	do{
		int res=0;
		for(int i=0;i<N;++i){
			for(int  j=i+1;j<N;++j){
				if(a[i]>a[j])++res;
			}
		}
		cnt[res]++;
	}while(next_permutation(a,a+N));
	for(int i=0;i<=N*(N-1)/2;++i){
		printf("cnt %d :%d\n",i,cnt[i]);
	}
	return 0;
}
