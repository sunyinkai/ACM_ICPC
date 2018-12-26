#include<cstdio>
#include<map>
using namespace std;
map<int,int>mp,t;
//应该用mp存,因为数组装不下
const int MAXN=1e5+7;
void getFac(int x,int mark){
	for(int i=2;i*i<=x;++i){
		while(x&&x%i==0){
			mp[i]+=1*mark;
			x/=i;
		}
	}
	if(x>=2)mp[x]+=1*mark;
}
int ans[MAXN],tot=0;
int main(){
	int N,M;
	while(~scanf("%d%d",&N,&M)){
		mp.clear();
		t.clear();
		tot=0;
		for(int i=2;i*i<=M;++i){
			while(M&&M%i==0){
				t[i]++;
				M/=i;
			}
		}//init mod
		if(M>=2)t[M]++;
		N--;
		for(int i=0;i<=N-1;++i){
			int x=N-i,y=i+1;
			getFac(x,1);
			getFac(y,-1);
			bool hasAns=true;
			for(auto it=t.begin();it!=t.end();++it){
				int num=it->first;
				if(t[num]>mp[num])hasAns=false;
			}
			if(hasAns){
				ans[tot++]=i+1;
				//printf("i=%d\n",i+1);
			}
		}
		printf("%d\n",tot);
		for(int i=0;i<tot;++i){
			printf(i==0?"%d":" %d",ans[i]+1);
		}
		printf("\n");
	}
	return 0;
}
