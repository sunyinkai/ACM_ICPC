#include<cstdio>
const int MAXN=22;
int a[MAXN];
int main(){
	int N,K;scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	bool isok=false;
	for(int i=1;i<(1<<N)-1;++i){
		int sum=0;
		for(int j=0;j<N;++j)
			if(i&(1<<j))sum+=a[j];
		if(sum==K)isok=true;
	}
	printf(isok?"Yes\n":"No\n");
	return 0;
}
