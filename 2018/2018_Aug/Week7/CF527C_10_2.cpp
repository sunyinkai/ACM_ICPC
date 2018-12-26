#include<cstdio>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
struct node{
	int x1,x2;
	node(int l,int r){
		x1=l;x2=r;
	}
	bool operator<(const node&other)const{
		return (x1-x2)>(other.x1-other.x2);
	}
};

set<int>st[2];
priority_queue<node>q[2];
void cut(int id,int len){
	st[id].insert(len);
	bool update=true;
	while(update){
		update=false;
		node t=q[id].top();
		int l=t.x1,r=t.x2;
		auto it=st[id].upper_bound(l);
		if(it==st[id].end())break;
		int x=*it;
		if(x<=r){
			update=true;
			st[id].erase(x);
			q[id].pop();
			q[id].push(node(l,x));
			q[id].push(node(x,r));
		}
	}
}
int main(){
	int N,M,Q;scanf("%d%d%d",&N,&M,&Q);
	q[0].push(node(0,N));
	q[1].push(node(0,M));
	while(Q--){
		char s[3];scanf("%s",s);
		int x;scanf("%d",&x);
		if(s[0]=='V')cut(0,x);
		else cut(1,x);
		node a=q[0].top();long long xx=a.x2-a.x1;
		node b=q[1].top();long long yy=b.x2-b.x1;
		printf("%lld\n",xx*yy);
	}
	return 0;
}
