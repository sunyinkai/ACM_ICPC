#include<bits/stdc++.h>
using namespace std;

const int MAXN=107;
int a[MAXN],b[MAXN];
int ans=0;
int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int b=-500;b<=500;++b){
		int c[MAXN];
		for(int i=1;i<=n;++i)c[i]=a[i];
		for(int i=-500;i<=500;++i){
			int num=b+i*k;
			if(num<0||num>n)continue;
			c[num]=0;
		}
		int cnt_1=0,cnt_2=0;
		for(int i=1;i<=n;++i)
			if(c[i]==1)++cnt_1;
			else if(c[i]==-1)++cnt_2;
		ans=max(ans,abs(cnt_1-cnt_2));

	}
	printf("%d\n",ans);
	return 0;
}
