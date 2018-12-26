#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
const int MAXN=2e6+7;
int cnt[MAXN],cnt2[MAXN];

void decompositon(int a[],int N){
	for(int i=1;i<=N;++i)a[i]=0;
	for(int i=2;i<=N;++i){
		int num=i;
		for(int j=2;j*j<=num;++j){
			int val=j,cnt=0;
			while(num%j==0){
				num/=j;
				++cnt;
			}
			a[val]=max(a[val],cnt);
		}
		if(num>1){
			a[num]=max(a[num],1);
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		decompositon(cnt,N);
	}
	return 0;
}
