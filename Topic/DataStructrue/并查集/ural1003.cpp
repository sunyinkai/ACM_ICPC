#include<cstdio>
#include<cstring>
#include<map>
const int MAXN=2e4+7;
using namespace std;
int a[MAXN],b[MAXN];
char s[MAXN][6];
int par[MAXN*2];
int visit[MAXN*2];
int find(int x){
	return par[x]==x?par[x]:par[x]=find(par[x]);
}
void unit(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		par[x]=y;
	}
}
int main(){
	int Q;
	while(~scanf("%d",&Q)&&(Q!=-1)){
		int N;scanf("%d",&N);
		map<int,int>m;
		m.clear();
		int tot=1;
		for(int i=1;i<=N;++i){
			scanf("%d%d%s",&a[i],&b[i],s[i]);
		}//input
		for(int i=1;i<=N;++i){
			if(!m[a[i]]){
				m[a[i]]=tot;
				tot+=2;
			}
			if(!m[b[i]]){
				m[b[i]]=tot;
				tot+=2;
			}
		}//离散化
		for(int i=0;i<=tot*2;++i){
			par[i]=i;
		}//init
		memset(visit,0,sizeof(visit));
		int ans=N;
		//printf("tot=%d\n",tot);
		for(int i=1;i<=N;++i){
			printf("a[i]=%d,b[i]=%d\n",a[i],b[i]);
			int x=m[a[i]],y=m[b[i]];
			x--;
			int x1=find(x),y1=find(y);
			int x2=find(x+tot),y2=find(y+tot);
			printf("visit[%d]=%d,visit[%d]=%d\n",x,visit[x],y,visit[y]);
			if(s[i][0]=='e'){
				if(x1!=y1){
					unit(x1,y1);
					unit(x2,y2);
				}else{
					if(x1==y2||x2==y1){
						ans=i;
						break;
					}
				}
			}else{
				if(x1!=y1){
					unit(x1,y2);
					unit(x2,y1);
					visit[x]=visit[y]=1;
				}else{
					if(x1==y1||x2==y2){
						ans=i;
						break;
					}
				}
			}
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
