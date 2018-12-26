#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1e5+7;
int a[MAXN];
int visit[MAXN];
vector<int>G[MAXN];
int main(){
	int N;scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&a[i]);
	int top=0;
	for(int i=1;i<=N;++i){
		if(!visit[i]){
			for(int j=i;!visit[j];j=a[j]){
				G[top].push_back(j);
				visit[j]=1;
			}
			++top;
		}
	}

	/*printf("top=%d\n",top);
	for(int i=0;i<top;++i){
		for(int j=0;j<G[i].size();++j)
			printf("%d ",G[i][j]);
		printf("\n");
	}
	printf("\n");
	*/
	int hasOne=0,oneid=0;
	int oddCnt=0;
	for(int i=0;i<top;++i){
		int x=G[i].size();
		if(x==1){
			hasOne=true;
			oneid=G[i][0];
		}
		if(x&1)++oddCnt;
	}
	if(hasOne){
		printf("YES\n");
		for(int i=1;i<=N;++i){
			if(i!=oneid)printf("%d %d\n",oneid,i);
		}
	}else{
		if(oddCnt>0){
			printf("NO\n");
		}//如果有奇环
		else{//都为偶数环，判断有没有２环
			int id=-1;
			for(int i=0;i<top;++i){
				int x=G[i].size();
				if(x==2){
					id=i;
					break;
				}
			}
			if(id==-1)printf("NO\n");
			else{
				printf("YES\n");
				int x0=G[id][0],y0=G[id][1];
				printf("%d %d\n",x0,y0);
				for(int i=0;i<top;++i){
					if(i==id)continue;
					int len=G[i].size();
					for(int j=0;j<len;++j){
						if(j&1)printf("%d %d\n",x0,G[i][j]);
						else printf("%d %d\n",y0,G[i][j]);
					}
				}
			}
		}
	}
	return 0;
}
