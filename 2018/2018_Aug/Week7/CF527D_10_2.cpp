#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;

struct node{
	int x,w;
	int id;
	int val;
	bool operator<(const node&other){
		return x+w<other.x+other.w;
	}
}no[MAXN];

int par[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d",&no[i].x,&no[i].w);
		no[i].id=i;
	}
	sort(no,no+N);

	int res=1;
	int prev=0;
	for(int i=1;i<N;++i){
		if(no[i].x-no[prev].x>=no[i].w+no[prev].w){
			++res;
			prev=i;
		}
	}
	printf("%d\n",res);
	return 0;
}
