#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int MAXN=5e4+7;
int a[MAXN];
int ans=0,N;
void solve(int len){
	if(len<=2)return;
	bool isok=true;
	int begin=1,end=len;
	while(1){
		bool has_peak=false;
		for(int i=begin;i<=end;++i){
			if(i==1||i==N)continue;
			if(a[i]>a[i-1]&&a[i]>a[i+1])has_peak=true;
		}
		begin+=len;end+=len;
		if(!has_peak)isok=false;
		if(begin>N)break;
	}
	if(isok)ans=max(ans,N/len);
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",&a[i]);
	for(int i=1;i*i<=N;++i){
		if(N%i==0){
			solve(i);
			solve(N/i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
