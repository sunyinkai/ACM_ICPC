#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;

struct node{
	int l,r;
	node(int x,int y):l(x),r(y){}
	bool operator<(const node&other)const{
		return (r-l)<(other.r-other.l);
	}
};

priority_queue<node>q1;
priority_queue<node>q2;
set<int>st1,st2;

void solve(priority_queue<node>&q1,priority_queue<node>&q2,set<int>&st1,int&x){
	st1.insert(x);
	while(1){
		node u=q1.top();q1.pop();
		int l=u.l,r=u.r;
		auto it=st1.lower_bound(l);
		if(it==st1.end()||(*it>r)){
			q1.push(u);
			break;
		}else{
			q1.push(node(l,*it));
			q1.push(node(*it,r));
			st1.erase(it);
		}
	}
	printf("%lld\n",(long long)(q1.top().r-q1.top().l)*(q2.top().r-q2.top().l));
}

int main(){
	int w,h,n;scanf("%d%d%d",&w,&h,&n);
	q1.push(node(0,h));
	q2.push(node(0,w));
	while(n--){
		char s[3];int x;
		scanf("%s%d",s,&x);
		if(s[0]=='H'){
			//与q1,st1有关
			solve(q1,q2,st1,x);
		}else{
			//与q2,st2有关
			solve(q2,q1,st2,x);
		}
	}
	return 0;
}
