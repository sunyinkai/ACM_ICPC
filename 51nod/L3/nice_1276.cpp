#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=5e4+7;
//从大往小加,考虑到每加一次至多会影响两个

struct node{
	int id;
	int val;
	bool operator<(const node&other)const{
		if(val<other.val)return false;
		else if(val==other.val)return id>other.id;
		return true;
	}
}no[MAXN];

int done[MAXN];
map<int,int>mp;
int main(){
	int N,Q;scanf("%d%d",&N,&Q);
	for(int i=1;i<=N;++i){
		scanf("%d",&no[i].val);
		no[i].id=i;
	}
	sort(no+1,no+1+N);
	int pre=no[1].val;
	int ans=1;done[no[1].id]=1;
	//printf("no[1].id=%d\n",no[1].id);
	int maxLevel=no[1].val;//the max level of land
	for(int i=2;i<=N;++i){
		maxLevel=max(maxLevel,no[i].val);
		if( no[i].val!=pre ){
			mp[pre]=ans;
	//		printf("mp[%d]:%d\n",pre,ans);
			pre=no[i].val;
		}
		done[ no[i].id ]=1;
		++ans;
		if(done[ no[i].id-1 ])--ans;
		if(done[ no[i].id+1 ])--ans;
	}
	mp[pre]=ans;
	//printf("mp[%d]:%d\n",pre,ans);

	while(Q--){
		int x;scanf("%d",&x);
		if(x>=maxLevel){
			printf("0\n");
		}else{
			auto it=mp.upper_bound(x);
			printf("%d\n",it->second);
		}
	}
	return 0;
}
