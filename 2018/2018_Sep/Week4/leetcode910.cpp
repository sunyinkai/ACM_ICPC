#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+7;
const int INF=1e9+7;

struct node{
	int val,id;
	bool operator<(const node&other)const{
		return val<other.val;
	}
}no[MAXN*2];

multiset<int>st;
int cnt[MAXN];//每个id出现的次数
//给每一个数a[i]加上或减去K,求最小的极差

int main(){
	int N,K;scanf("%d%d",&N,&K);
	for(int i=1;i<=N;++i){
		int x;scanf("%d",&x);
		no[i].val=x+K;no[i].id=i;
		no[i+N].val=x-K;no[i+N].id=i;
	}
	sort(no+1,no+2*N+1);

	int size=0,i=1,j=1;
	int res=INF;
	while(i<=2*N&&j<=2*N){
		while(i<=2*N&&size<N){
			if(!cnt[no[i].id]){
				++size;
			}
			cnt[no[i].id]++;
			++i;
		}
	//	printf("i=%d,j=%d,size=%d,no[i].val=%d,no[j].val=%d\n",i-1,j,size,no[i-1].val,no[j].val);
		if(size==N)res=min(res,no[i-1].val-no[j].val);
		cnt[no[j].id]--;
		if(cnt[no[j].id]==0)--size;
		++j;
	}
	printf("%d\n",res);
	return 0;
}
