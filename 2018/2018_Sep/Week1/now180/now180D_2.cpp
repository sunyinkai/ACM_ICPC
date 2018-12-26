#include<cstdio>
#include<cstring>
const int MAX_BASE=30;
int b[MAX_BASE+1];
bool insert(int val){
	for(int i=MAX_BASE;i>=0;--i){
		if(val&(1<<i)){
			if(!b[i]){b[i]=val;break;}
			val^=b[i];
		}
	}
	return val>0;
}

int main(){
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		int x;scanf("%d",&x);
		insert(x);
	}
	int Q;scanf("%d",&Q);
	while(Q--){
		int x,y;scanf("%d%d",&x,&y);
		x^=y;
		for(int i=MAX_BASE;i>=0;--i){
			if((x&(1<<i)))x^=b[i];
		}
		if(x)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
