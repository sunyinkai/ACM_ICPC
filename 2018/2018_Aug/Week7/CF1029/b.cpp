#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=2e5+7;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	int ans=0;
	int j=1,i;
	for(i=2;i<=N;){
		while(i<=N&&a[i]<=2*a[i-1]){
			++i;
			ans=max(ans,i-j);
		}
		j=i;
		++i;
	}
	ans=max(ans,i-j);
	printf("%d\n",ans);
	return 0;
}
