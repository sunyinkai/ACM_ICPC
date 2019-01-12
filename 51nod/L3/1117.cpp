#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;scanf("%d",&N);
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		q.push(x);
	}

	long long ans=0;
	while(!q.empty()){
		int u=q.top();q.pop();
		int v;
		if(!q.empty())v=q.top(),q.pop();
		else break;
		ans+=u+v;
		q.push(u+v);
	}
	printf("%lld\n",ans);
	return 0;
}
