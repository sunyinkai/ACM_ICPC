#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=1e5+7;
int left[MAXN],right[MAXN],a[MAXN];
struct node{
	int val,id;
	bool operator <(const node&other)const{
		return val<other.val||id>other.id;
	}//找值比它大的,id最小的数
};
set<node>st;
int main(){
	for(int i=0;i<10;++i){
		st.insert(node{i,i+10});
	}
	printf("%d\n",st.size());
	return 0;
}
