#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e4+7;
int a[MAXN];
int q[MAXN],r[MAXN],l[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	a[0]=a[N+1]=-1;//加入两个辅助元素
	int top=0;
	for(int i=1;i<=N+1;++i){
		if(top==0||a[i]>=a[q[top-1]])q[top++]=i;
		else{
			while(top>0&&a[i]<a[q[top-1]]){
				r[q[top-1]]=i;
				--top;
			}
			q[top++]=i;
		}
	}

	top=0;
	for(int i=N;i>=0;--i){
		if(top==0||a[i]>=a[q[top-1]])q[top++]=i;
		else{
			while(top>0&&a[i]<a[q[top-1]]){
				l[q[top-1]]=i;
				--top;
			}
			q[top++]=i;
		}
	}
	long long ans=0;
	for(int i=1;i<=N;++i)
		ans=max(ans,(long long)(r[i]-l[i]-1)*a[i]);
	printf("%lld\n",ans);
	return 0;
}
