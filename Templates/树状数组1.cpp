#include<cstdio>
#include<cstring>
const int MAXN=5e5+7;
int a[MAXN],N,M;

inline int  lowbit(int i){ 
	return i&-i;
}

void add(int i,int x){ 
	if(i==0)return ;
	while(i<=N){ 
		a[i]+=x;
		i+=lowbit(i);
	}
}

int sum(int i){ 
	int res=0;
	while(i){ 
		res+=a[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){ 
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i){ 
		int x;scanf("%d",&x);
		add(i,x);
	}
	for(int i=0;i<M;++i){ 
		int q;scanf("%d",&q);
		if(q==1){ 
			int x,k;
			scanf("%d%d",&x,&k);
			add(x,k);
		}else{ 
			int x,y;scanf("%d%d",&x,&y);
			printf("%d\n",sum(y)-sum(x-1));
		}
	}
	return 0;
}
