#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
//3个数和为0
const int MAXN=1007;
struct node{
	long long val;
	int id;
	bool operator<(const node&other)const{
		if(val<other.val)return true;
		else if(val==other.val)return id<other.id;
		else return false;
	}
}no[MAXN*MAXN];

long long a[MAXN];
map<long long,int>mp;

struct tmp{
	long long a[3];
	bool operator<(const tmp&other)const{
		for(int i=0;i<3;++i){
			if(a[i]==other.a[i])continue;
			return a[i]<other.a[i];
		}
		return false;
	}
}ans[MAXN*MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%lld",&a[i]);
	int top=0;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			no[top].id=i*MAXN+j;
			no[top++].val=a[i]+a[j];
		}
	}

	sort(no,no+top);
	int tot=0;
	for(int i=0;i<N;++i){
		node t;t.id=-1;
		t.val=-a[i];
		int begin=lower_bound(no,no+top,t)-no;
		t.val=-a[i]+1;
		int end=lower_bound(no,no+top,t)-no;
		for(int it=begin;it<end;++it){
			int idx=no[it].id%MAXN,idy=no[it].id/MAXN;

			if(i==idx||i==idy)continue;
			int tt[3]={i,idx,idy};
			sort(tt,tt+3);
			long long val=(long long)tt[0]*MAXN*MAXN+tt[1]*MAXN+tt[2];
			if(mp[val])continue;//去重
			mp[val]=1;

			for(int i=0;i<3;++i)tt[i]=a[tt[i]];
			sort(tt,tt+3);
			for(int i=0;i<3;++i)
				ans[tot].a[i]=tt[i];
			++tot;
		}
	}
	if(tot==0){
		printf("No Solution\n");
		return 0;
	}
	sort(ans,ans+tot);
	for(int i=0;i<tot;++i)
		printf("%lld %lld %lld\n",ans[i].a[0],ans[i].a[1],ans[i].a[2]);
	return 0;
}
