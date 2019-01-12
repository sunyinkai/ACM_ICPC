#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
struct node{
	long long id,val;
	bool operator<(const node&other)const{
		return val<other.val;
	}
}no[MAXN*MAXN];
int a[MAXN];

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			no[i*N+j].id=i*N+j,no[i*N+j].val=a[i]+a[j];
	sort(no,no+N*N);
	int i=0,j=N*N-1;
	bool has_ans=false;
	while(i<j){
		if(no[i].val+no[j].val==0){
			long long a[4]={no[i].id%N,no[i].id/N,no[j].id%N,no[j].id/N};
			sort(a,a+4);

			int isok=(unique(a,a+4)-a)==4;
			if(isok){
				has_ans=true;
			}
			++i;--j;
		}else if(no[i].val+no[j].val>0)--j;
		else ++i;
	}
	printf(has_ans?"Yes\n":"No\n");
	return 0;
}
