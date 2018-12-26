#include<cstdio>
int main(){ 
	int n,v;
	int q[1000],top=0;
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;++i){ 
		int k;scanf("%d",&k);
		int flag=0;
		for(int j=0;j<k;++j){ 
			int x;scanf("%d",&x);
			if(v>x){ 
				if(!flag)q[top++]=i;
				flag=1;
			}
		}
	}

	printf("%d\n",top);
	for(int i=0;i<top;++i){ 
		printf("%d ",q[i]);
	}
	return 0;
}
