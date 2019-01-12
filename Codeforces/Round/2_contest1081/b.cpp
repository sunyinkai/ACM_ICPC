#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+7;
int a[MAXN];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int cnt[MAXN];
struct node{
	int num,id;
	int val;
	bool operator<(const node&other)const{
		return num<other.num;
	}
}no[MAXN];

int ans[MAXN];
int main(){
	int N;scanf("%d",&N);
	int hasZero=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&no[i].num);
		a[i]=no[i].num;
		if(a[i]==0)hasZero=1;
		no[i].id=i;
		cnt[no[i].num]++;
	}

	bool hasAns=true;
	for(int i=1;i<=N;++i){
		int x=N-a[i];
		if(cnt[i]%x!=0)hasAns=false;
	}

	if(!hasAns){
		printf("Impossible\n");
		return 0;
	}
	else{
		int base=0;
		printf("Possible\n");
		if(hasZero){
			for(int i=1;i<=N;++i)
				printf("%d ",1);
			return 0;
		}
		sort(no+1,no+N+1);
		for(int i=1;;){
			int x=cnt[no[i].num];
			int group_size=x/(N-a[no[i].id]);//size:group
			if(group_size==0)break;
			for(int j=i;j<i+x;++j){
				if((j-i)%(x/group_size)==0)++base;
				no[j].val=base;
			}
			i=i+x;
			if(i==N)break;
		}
	}
	for(int i=1;i<=N;++i)
		ans[no[i].id]=no[i].val;
	for(int i=1;i<=N;++i)
		printf("%d ",ans[i]);
	return 0;
}
