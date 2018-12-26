#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
int main(){
	int N;scanf("%d",&N);
	priority_queue<int,vector<int>,less<int> >q;
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		q.push(x);
	}
	long long ans=0;
	while(q.size()>1){
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans+=y;
		q.push(x-y);
	}
	printf("%lld\n",ans);
	return 0;
}
