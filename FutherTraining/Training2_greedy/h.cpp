#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1007;
int a[MAXN],b[MAXN];
int main(){
	int N;
	while(~scanf("%d",&N)&&N){
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		for(int i=0;i<N;++i)scanf("%d",&b[i]);
		sort(a,a+N);
		sort(b,b+N);
		int Alast=N-1,Blast=N-1,id1=0,id2=0;
		int res=0;
		while(id1<=Alast&&id2<=Blast){
			if(a[id1]>b[id2]){
				++res;
				++id1;++id2;
			}else{
				if(a[Alast]>b[Blast]){
					++res;
					--Alast,--Blast;
				}else{
					if(a[id1]!=b[Blast])--res;
					++id1;--Blast;
				}
			}
		}
		printf("%d\n",res*200);
	}
	return 0;
}
