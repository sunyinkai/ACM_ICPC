#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=1e4+7;
int x[MAXN],y[MAXN];
//不应该记录斜率,记录两条边即可
struct node{
	int x,y;
	bool operator <(const node&other)const{
		return x<other.x||(x==other.x&&y<other.y);
	}
}no[MAXN];

int top=0;

int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d%d",&x[i],&y[i]);
	long long lenx=1,leny=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(j==i)continue;
			long long tx=x[j]-x[i];
			long long ty=y[j]-y[i];
			if(lenx*ty>=tx*leny){
				if(lenx*ty==tx*leny){
					++top;
					no[top].x=i;no[top].y=j;
				}else{
					top=0;
					no[top].x=i;no[top].y=j;
					lenx=tx;leny=ty;
				}
			}
		}
	}

	sort(no,no+top+1);
	for(int i=0;i<=top;++i){
		if(x[no[i].x]>x[no[i].y])
			swap(no[i].x,no[i].y);
		printf("%d %d\n",no[i].x,no[i].y);
	}
	return 0;
}

