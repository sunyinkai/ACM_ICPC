#include<cstdio>
#include<cstring>
const int MAXV=3e5+7;
const int MAXE=2e7+6;
struct edge{ 
	int to,next;
}es[MAXE];
int head[MAXE],tot;

void init(){ 
	memset(head,-1,sizeof(head));
	tot=0;
}
void addEdge(int a,int b){ 
	es[tot].to=b;
	es[tot].next=head[a];
	head[a]=tot++;
}
int in[MAXE],out[MAXE];
int visit[MAXE];
int time;
int Stack[MAXE],top;
void dfs(int u){ 
	visit[u]=1;
	in[u]=++time;
	top=0;
	Stack[top++]=u;
	while(top!=0){ 
		int u=Stack[--top];
		for(int i=head[u];~i;i=es[i].next){ 
			int v=es[i].to;
			if(visit[v])continue;
			Stack[top++]=v;
		}
		out[u]=time;
	}
}
int main(){ 
	int T;scanf("%d",&T);
	int tag=0;
	for(int test=1;test<=T;++test){ 
		if(tag)printf("\n");
		int N;scanf("%d",&N);
		memset(visit,0,sizeof(visit));
		tag=1;
		int now=1;
		init();
		for(int i=0;i<N;++i){ 
			int x;scanf("%d",&x);
			for(int j=0;j<x;++j){ 
				printf("%d->%d\n",i,now);
				addEdge(i,now);
				addEdge(now,i);
				++now;
			}
		}
		time=0;
		dfs(0);
		int Q;scanf("%d",&Q);
		printf("Case %d:\n",test);
		while(Q--){ 
			int u,v;scanf("%d%d",&u,&v);
			if(out[v]<=out[u]&&in[v]>=in[u]){ 
				printf("Yes\n");
			}else{ 
				printf("No\n");
			}
		}
	}
	return 0;
}
