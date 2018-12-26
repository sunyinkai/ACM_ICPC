#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
int a[MAXN],N;
struct BIT{
	int a[MAXN];
	int lowbit(int i){return i&-i;}
	int sum(int i){
		int res=0;
		for(;i;i-=lowbit(i))res+=a[i];
		return res;
	}
	void add(int p,int x){
		for(;p<=N;p+=lowbit(p))a[p]+=x;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
}x,y;

int left[MAXN],right[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		x.clear();y.clear();
		for(int i=1;i<=N;++i){
			left[i]=x.sum(a[i]);
			x.add(a[i],1);
		}//left[i] : k<i && a[k] <a[i]
		for(int i=N;i>=1;--i){
			right[i]=y.sum(a[i]);
			y.add(a[i],1);
		}//right[i]: k>i && a[k]<a[i]
		long long res=0;
		for(int i=1;i<=N;++i){
			res+=(long long)left[i]*(N-i-right[i]);
			res+=(long long)(i-left[i]-1)*right[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}
