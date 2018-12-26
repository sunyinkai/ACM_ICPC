#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
const int MAXN=1e4+7;
const double eps=1e-6;

struct node{
	double l,r;
	bool operator<(const node&other)const{
		return l<other.l||(l==other.l&&r<other.r);
	}
}no[MAXN];
int main(){
	int n,l,w;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d%d%d",&n,&l,&w)){
		int top=0,p,r;
		for(int i=0;i<n;++i){
			scanf("%d%d",&p,&r);
			double val=r*r*1.0-w*w*1.0/4;
			if(r<=w*1.0/2)continue;
			no[top].l=p-sqrt(val);
			no[top++].r=p+sqrt(val);
		}

		bool hasAns=true;
		double nowl=0.0,maxr=0.0;
		int res=0;
		sort(no,no+top);
		if(no[0].l<=0){
			int i=0;
			for(;i<top;){
				int j=i;
				while(j<top&&no[j].l<=nowl){
					maxr=max(maxr,no[j].r);
					++j;
				}
				if(j==i){
					hasAns=false;
					break;
				}
				++res;
				nowl=maxr;
				i=j;
				if(nowl>=l)break;
			}
		}
		//printf("nowl=%.6f\n",nowl);
		if(!hasAns||nowl<l)printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}
