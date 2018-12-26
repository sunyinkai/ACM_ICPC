#include<cstdio>
#include<map>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> P;
const ull base=131,base2=131;
const ull mod=19260817,mod2=19660813;
int main(){
	int N;scanf("%d",&N);getchar();
	int ans=0;
	map<P,int>mp;
	while(N--){
		char ch;
		ull res=0,res2=0;
		while((ch=getchar())!='\n'){
			res=(res*base+ch)%mod;
			res2=(res2*base2+ch)%mod2;
		}
		if(!mp[P(res,res2)])++ans,mp[P(res,res2)]=1;
	}
	printf("%d\n",ans);
	return 0;
}

