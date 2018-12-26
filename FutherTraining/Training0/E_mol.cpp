#include<cstdio>
//每次删除两个不同的数
int main(){
	int N;
	while(~scanf("%d",&N)){
		int ans=-1,cnt=0,prev=-1;
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			if(cnt==0){
				ans=x;
				cnt=1;
			}else{
				cnt+=(x==ans?1:-1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
