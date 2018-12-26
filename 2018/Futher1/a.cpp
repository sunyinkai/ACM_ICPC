#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=3007;
int num[MAXN];
int main(){ 
	int n,v;scanf("%d%d",&n,&v);
	for(int i=0;i<n;++i){ 
		int x,y;scanf("%d%d",&x,&y);
		num[x]+=y;
	}
	int prev=0;
	int res=0;
	for(int i=1;i<MAXN;++i){ 
		int x;
		x=num[i];
	//	printf("prev=%d,now=%d\n",prev,x);
		if(prev>=v){
			res+=v;
			prev=x;
		}else{ 
			int remain=v-prev;//剩下的采摘力
			res+=prev;
			if(remain>=x){ 
				prev=0;
				res+=x;
			}else{ 
				res+=remain;
				prev=x-remain;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
