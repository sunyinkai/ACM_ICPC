#include<cstdio>
#include<cstring>
#include<cstdlib>
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

int in[MAXN],out[MAXN],time;

void dfs(int u){ 
	in[u]=++time;
	for(int i=head[u];~i;i=es[i].next){ 
		int v=es[i].to;
		dfs(v);
	}
	out[u]=time;
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

		time=0;
		dfs(0);
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
