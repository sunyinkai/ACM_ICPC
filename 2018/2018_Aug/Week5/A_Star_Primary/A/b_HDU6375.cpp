#include<cstdio>
#include<cstring>
#include<list>
using namespace std;
const int MAXN=150007;
list<int>ls[MAXN];
int cnt[MAXN];
//ctrl + D EOF
//不能关闭同步
//只能读入int
int read(){
	char ch = getchar();
	int x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	return x;
}
int main(){
	int N,Q;
	while(~scanf("%d%d",&N,&Q)){
		for(int i=0;i<=N;++i)cnt[i]=0,ls[i].clear();
		while(Q--){
			int x;
			x=read();
			if(x==1){
				int u,w,val;
				u=read();w=read();val=read();
				if(w==0){
					ls[u].push_front(val);
				}else{
					ls[u].push_back(val);
				}
				cnt[u]++;
			}else if(x==2){
				int u,w;
				u=read();w=read();
				//do_something
				if(cnt[u]==0){
					printf("-1\n");
					continue;
				}
				int num;
				if(w==0){
					num=ls[u].front();
					ls[u].pop_front();
				}else{
					num=ls[u].back();
					ls[u].pop_back();
				}
				printf("%d\n",num);
				cnt[u]--;
			}else{//merge
				int u,v,w;
				u=read();v=read();w=read();
				cnt[u]+=cnt[v];
				cnt[v]=0;
				if(w==0){
					ls[u].splice(ls[u].end(),ls[v]);
				}else{
					ls[v].reverse();
					ls[u].splice(ls[u].end(),ls[v]);
				}
			}
		}
	}
	return 0;
}
