//二分+贪心
//r越小越先处理

#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e4+7;
struct node{
	int l,r,w;
	bool operator<(const node&other)const{
		return r>other.r;
	}
}no[MAXN];
bool cmp(node&a,node&b){
	return a.l<b.l;
}

int N;
bool isok(int x){
	priority_queue<node>q;
	int i=0;
	for(int t=1;t<=20000;++t){
		while(i<N&&no[i].l==t){
			q.push(no[i]);
			++i;
		}//加入
		//r越小，越先做
		int w=x;//1个单位时间的工作量
		while(!q.empty()&&w!=0){
			node ne=q.top();q.pop();
	//		printf("ne.r=%d\n",ne.r);
			if(ne.r<t)return false;

			if(ne.w>=w){
				ne.w-=w;
				if(ne.w!=0)q.push(ne);
				w=0;
			}else{//ne.w < w
				w-=ne.w;
			}
		}
	}
	return true;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d%d%d",&no[i].l,&no[i].r,&no[i].w);
			no[i].r--;
		}
		sort(no,no+N,cmp);
		int hi=1e9+7,lo=0;
		while(hi-lo>1){
			int mid=(hi+lo)/2;
			if(isok(mid))hi=mid;
			else lo=mid;
		}
		printf("%d\n",hi);
	}
	return 0;
}
