//1191 消灭兔子
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+7;
struct node{
	int damage,cost;
}no[MAXN];

struct cmp{
	bool operator()(const node& a,const node& b)const {
		return a.cost>b.cost;
	}
};

int a[MAXN];
priority_queue<node,vector<node>,cmp>q;

int main(){
	int N,M;scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)scanf("%d",&a[i]);
	for(int i=0;i<M;++i)scanf("%d%d",&no[i].damage,&no[i].cost);
	sort(a,a+N,greater<int>());
	sort(no,no+M,[](const node& a,const node&b)->bool{
			return a.damage>b.damage;});

	bool hasAns=true;
	long long ans=0;
	int i=0,j=0;
	for(i=0;i<N;++i){
		int x=a[i];
		while(j<M && no[j].damage>=x)q.push(no[j++]);
		if(q.empty()){
			hasAns=false;
			break;
		}
		node u=q.top();q.pop();
		ans+=u.cost;
	}
	if(hasAns)printf("%lld\n",ans);
	else printf("No Solution\n");
	return 0;
}
