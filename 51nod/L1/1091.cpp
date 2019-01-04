#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4+7;
struct node{
	int l,r;
	bool operator<(const node&other)const{
		return l<other.l||(l==other.l&&r>other.r);
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d",&no[i].l,&no[i].r);
	sort(no,no+N);
	int ans=0;
	int max_end=no[0].r;
	for(int i=1;i<N;++i){
		if(no[i].l>max_end);
		else{
			ans=max(ans,min(max_end,no[i].r)-no[i].l);
		}
		max_end=max(max_end,no[i].r);
	}
	printf("%d\n",ans);
	return 0;
}
