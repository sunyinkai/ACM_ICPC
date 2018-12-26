#include<cstdio>
#include<cstring>
const int MAXN=8007;
int a[MAXN];
int ans[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)){
		memset(a,-1,sizeof(a));
		while(N--){
			int l,r,x;scanf("%d%d%d",&l,&r,&x);
			for(int i=l;i<=r-1;++i)
				a[i]=x;
		}
		int prev;
		//int b[10];
		ans[a[0]]=1;prev=a[0];
		for(int i=1;i<=8000;++i){
			if(a[i]==prev)continue;
			else{
				ans[a[i]]++;
				prev=a[i];
			}
		}

		for(int i=0;i<=8000;++i){
			if(ans[i])printf("%d %d\n",i,ans[i]);
			ans[i]=0;
		}
		printf("\n");
	}
	return 0;
}
