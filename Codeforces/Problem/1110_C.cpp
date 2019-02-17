#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=27;
int a[MAXN];
void init(){
	int ans=2;
	for(int i=0;i<=26;++i){
		a[i]=ans-1,ans*=2;
	}
}

map<int,int>mp;

int main(){
	init();
	int Q;scanf("%d",&Q);
	while(Q--){
		int q;scanf("%d",&q);
		if(lower_bound(a,a+27,q)==upper_bound(a,a+27,q)){
			printf("%d\n",a[lower_bound(a,a+27,q)-a]);
		}
		else {
			if(!mp[q]){
				int ans=1;
				for(int i=2;i*i<=q;++i){
					if(q%i==0){
						ans=max(ans,i);
						ans=max(ans,q/i);
					}
				}
				mp[q]=ans;
			}
			printf("%d\n",mp[q]);
		}
	}
	return 0;
}
