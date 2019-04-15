//tag: greedy
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
struct node{
	int a,b;
	bool operator<(const node&other)const{
		return max(a,b+other.a)<max(other.a,a+other.b);
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d",&no[i].a,&no[i].b);
	sort(no,no+N);

	int ans=0,now=0;
	for(int i=0;i<N;++i){
		ans=max(ans,now+no[i].a);
		now+=no[i].b;
	}
	printf("%d\n",ans);
	return 0;
}
