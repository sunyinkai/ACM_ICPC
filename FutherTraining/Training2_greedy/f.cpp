#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=1e5+7;
struct node{
	int w,h;
	bool operator<(const node&other)const{
		return w<other.w;
	}
}a[MAXN],b[MAXN];
multiset<int>st;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=0;i<N;++i)scanf("%d%d",&a[i].w,&a[i].h);
		for(int i=0;i<N;++i)scanf("%d%d",&b[i].w,&b[i].h);
		sort(a,a+N);
		sort(b,b+N);
		st.clear();
		int res=0;
		for(int i=0,j=0;i<N;++i){
			while(j<N&&a[i].w>=b[j].w)st.insert(b[j++].h);//保证在st里的w一定比外面的小
			if(st.empty())continue;
			set<int>::iterator it=st.lower_bound(a[i].h);
			if(*it!=a[i].h){
				if(it!=st.begin())--it;
				else continue;
			}
			st.erase(it);
			++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
