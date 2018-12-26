#include<cstdio>
const int INF=1e9+7;
int main(){
	int S;scanf("%d",&S);
	int ans=INF;
	for(int i=1;i*i<=S;++i){
		if(S%i==0){
			if(ans>(i+S/i)*2)
				ans=(i+S/i)*2;
		}
	}
	printf("%d\n",ans);
	return 0;
}
