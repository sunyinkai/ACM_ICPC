#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
struct node{
	int id,val;
	bool operator<(const node&other)const{
		return val<other.val;
	}
}no[MAXN];
priority_queue<node>q;
int visit[MAXN];
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		no[i].id=i;
		scanf("%d",&no[i].val);
		q.push(no[i]);
	}
	long long ans=0;
	for(int i=0;i<m*k;++i){
		node t=q.top();q.pop();
		ans+=t.val;
		visit[t.id]=1;
	}
	printf("%lld\n",ans);
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=visit[i];
		if(sum==m){
			sum=0;
			if(i==n)break;
			printf("%d ",i);
		}
	}
	return 0;
}
