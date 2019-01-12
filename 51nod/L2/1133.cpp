#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+7;
const int INF=1e9+7;
struct node{
	int l,r;
	bool operator<(const node&other)const{
		return r<other.r||(r==other.r&&l<other.l);
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d",&no[i].l,&no[i].r);
	sort(no,no+N);
	int end=-INF,ans=0;
	for(int i=0;i<N;++i){
		if(no[i].l<end);
		else{
			end=max(end,no[i].r);
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
