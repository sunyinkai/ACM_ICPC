#include<cstdio>
#include<map>
using namespace std;
const int INF=1e9+7;
map<int,int>mp;

int main(){
	int N,a,b;scanf("%d%d%d",&N,&a,&b);
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		mp[x]=1;
	}

	bool isok=true;
	for(auto it=mp.begin();it!=mp.end();++it){
		int x=it->first;
		if(mp[a-x]||mp[b-x]);
		else isok=false;
	}

	printf(isok?"YES\n":"NO\n");
	return 0;
}
