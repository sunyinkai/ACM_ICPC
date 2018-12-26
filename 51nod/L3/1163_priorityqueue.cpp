#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+7;
struct node{
	int e,w;
	node(){
		e=w=0;
	}
	bool operator<(const node&other)const{
		if(e>other.e)return true;
		else if(e==other.e)return w>other.w;
		else return false;
	}
}no[MAXN];

priority_queue<int,vector<int>,less<int> >q;
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d%d",&no[i].e,&no[i].w);
	sort(no,no+N);
	long long ans=0;
	for(int i=0;i<N;++i){
	//	printf("id:%d %d %d\n",i,no[i].e,no[i].w);
		q.push(no[i].w);
		int day_gap=no[i].e-no[i+1].e;
		while(day_gap&&!q.empty()){
			int u=q.top();q.pop();
			ans+=u;
			day_gap--;
		}
	//	printf("ans:%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}
