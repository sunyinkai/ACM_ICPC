#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
const int INF=1e9+7;
int sum[MAXN];
struct node{
	int l,r,id;
	bool operator<(const node&other)const{
		return l<other.l||(l==other.l&&r>other.r);
	}
}no[MAXN];

int ans[MAXN];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d%d",&no[i].l,&no[i].r);
			no[i].id=i;
		}
		sort(no,no+N);

		int right=no[0].r;
		int id=-1;
		for(int i=0;i<=N;++i)ans[i]=0;
		for(int i=1;i<N;++i){
			if(no[i].l>right){
				id=i;
				break;
			}
			right=max(right,no[i].r);
		}

		if(id==-1)printf("-1\n");
		else{
			for(int i=0;i<id;++i)
				ans[no[i].id]=1;
			for(int i=id;i<N;++i)
				ans[no[i].id]=2;

			for(int i=0;i<N;++i)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
