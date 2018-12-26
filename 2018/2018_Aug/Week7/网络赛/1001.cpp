#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int x,id;
	node(int a,int b){
		x=a;id=b;
	} bool operator<(const node&other)const{
		return x>other.x||(x==other.x&&id>other.id);
	}
};

priority_queue<node>q;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		while(!q.empty())q.pop();
		int N;scanf("%d",&N);
		long long ans=0,cnt=0;
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			if(!q.empty()&&q.top().x<x){
				node t=q.top();q.pop();
				ans+=x-t.x;
				q.push(node(x,1));
				q.push(node(x,0));
			}else{q.push(node(x,1));}
		}

		while(!q.empty()){
			node t=q.top();q.pop();
			if(t.id==0)++cnt;
		}
		printf("%lld %lld\n",ans,cnt*2);
	}
	return 0;
}
