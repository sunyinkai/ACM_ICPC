#include<cstdio>
#include<cstring>
const int MAXN=2e7+7;
struct edge{ 
	int to,next;
}es[MAXN];
int head[MAXN],tot,now;
void init(){ 
	memset(head,-1,sizeof(head));
	tot=0;
}
void addEdge(int a,int b){ 
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}

int in[MAXN],out[MAXN];
int q[MAXN],id[MAXN],visit[MAXN];
void solve(){ 
	int top=0,time=0;
	q[top++]=0;
	for(int i=0;i<now;++i){ 
		id[i]=head[i];
	}

	while(top!=0){ 
		int u=q[top-1];
		int &i=id[u];
		if(visit[u]==0){ 
			visit[u]=1;//first in
			in[u]=++time;
		//	printf("in[%d]=%d\n",u,in[u]);
		}
		for(i=head[u];~i;i=es[i].next){ 
			int v=es[i].to;
			if(visit[v]==2)continue;
			q[top++]=v;
			break;
		}

		if(i==-1){ 
			--top;//pop out
			out[u]=time;
			visit[u]=2;
		//	printf("out[%d]=%d\n",u,out[u]);
		}
	}
}

int main(){ 
	int T;scanf("%d",&T);
	int tag=0;
	for(int test=1;test<=T;++test){ 
		if(tag)printf("\n");
		tag=1;
		int N;scanf("%d",&N);
		now=1;
		init();

		for(int i=0;i<N;++i){ 
			int x;scanf("%d",&x);
			for(int j=0;j<x;++j){ 
				addEdge(i,now);
				now++;
			}
		}//addEdge

		for(int i=1;i<=now;++i)in[i]=out[i]=visit[i]=0;
		solve();
		printf("Case %d:\n",test);
		int M;scanf("%d",&M);
		for(int i=0;i<M;++i){ 
			int a,b;scanf("%d%d",&a,&b);
			if(a==b){ 
				printf("No\n");
				continue;
			}
			if(in[a]<=in[b]&&out[a]>=out[b]){ 
				printf("Yes\n");
			}else{ 
				printf("No\n");
			}
		}
	}
	return 0;
}
