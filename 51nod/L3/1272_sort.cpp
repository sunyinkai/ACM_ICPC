#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4+7;
struct node{
	int id,val;
	bool operator<(const node&other)const{
		return val<other.val||(val==other.val&&id<other.id);
	}
}no[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&no[i].val);
		no[i].id=i;
	}
	sort(no,no+N);
	int max_id=0,ans=0;
	for(int i=N-1;i>=0;--i){
		max_id=max(max_id,no[i].id);
		ans=max(ans,max_id-no[i].id);
	}
	printf("%d\n",ans);
	return 0;
}
