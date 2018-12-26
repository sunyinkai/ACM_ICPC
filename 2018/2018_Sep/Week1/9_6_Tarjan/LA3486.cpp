#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
//考虑a==b的情况
//递归深度太深,会爆炸
const int MAXN=2e7+7;
struct edge{
	int to,next;
}es[MAXN];
int tot,head[MAXN];
void init(){
	tot=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int a,int b){
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int top=0;
int in[MAXN],out[MAXN],id[MAXN];
stack<int>st;
void solve(int N){
	int time=0;
	st.push(0);
	for(int i=0;i<=N;++i)id[i]=head[i];

	while(!st.empty()){
		int u=st.top();
	//	printf("u=%d\n",u);
		if(id[u]==head[u])in[u]=++time;
		if(id[u]==-1){
			out[u]=time;
			st.pop();
		}else{
			int v=es[id[u]].to;
			id[u]=es[id[u]].next;
			st.push(v);
		}
	}

	/*for(int i=0;i<=N;++i)
		printf("in[%d]=%d,out[%d]=%d\n",i,in[i],i,out[i]);*/
}

int main(){
	int T;scanf("%d",&T);
	int blank=0;
	for(int test=1;test<=T;++test){
		if(blank)printf("\n");
		blank=1;
		int N;scanf("%d",&N);
		init();
		top=0;
		for(int i=0;i<N;++i){
			int x;scanf("%d",&x);
			for(int j=0;j<x;++j){
				++top;
				addEdge(i,top);
			//	printf("%d--->%d\n",i,top);
			}
		}
		solve(top);
		printf("Case %d:\n",test);
		int M;scanf("%d",&M);
		while(M--){
			int a,b;scanf("%d%d",&a,&b);
			if(a==b){
				printf("No\n");
			}
			else if(in[a]<=in[b]&&out[b]<=out[a])printf("Yes\n");
			else printf("No\n");
		}

	}
	return 0;
}
