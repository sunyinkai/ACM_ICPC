//*注意:在每一段结束的时候计数
//可以作为hash过后的后续工作
//好处是浮点数计数

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i)scanf("%d",&a[i]);
	sort(a,a+N);
	int prev=a[0],cnt=1;
	for(int i=1;i<N;++i){
		if(a[i]==prev){
			++cnt;
		}else{
			printf("num=%d,cnt=%d\n",prev,cnt);
			prev=a[i];
			cnt=1;
		}
	}
	printf("num=%d,cnt=%d\n",prev,cnt);
	return 0;
}
