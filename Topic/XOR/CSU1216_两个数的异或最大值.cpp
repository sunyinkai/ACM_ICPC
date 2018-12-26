#include<cstdio>
#include<cstring>
#define root 0
const int MAXN=1e5+7;
int ch[MAXN*16][2];
int a[MAXN];
int tot=1;
void insert(const int *s){
	int now=root;
	for(int i=31;i>=0;--i){
		int num=s[i];
		if(!ch[now][num]) ch[now][num]=tot++;
		now=ch[now][num];
	}
}
long long query(int x){
	int s[32];
	for(int i=0;i<32;++i){
		s[i]=x%2;
		x/=2;
	}

	int now=root;
	long long res=0;
	for(int i=31;i>=0;--i){
		res<<=1;
		int val=s[i];
		if(val&1){//val==1
			if(ch[now][0])now=ch[now][0],res+=1;
			else now=ch[now][1];
		}else{//val==0
			if(ch[now][1])now=ch[now][1],res+=1;
			else now=ch[now][0];
		}
	}
	return res;
}
int main(){
	int N;
	while(scanf("%d",&N)&&N){
		memset(ch,0,sizeof(ch));
		tot=1;
		for(int i=0;i<N;++i){
			scanf("%d",&a[i]);
			int s[32],tmp=a[i];
			for(int i=0;i<32;++i){
				s[i]=tmp%2;
				tmp/=2;
			}
			insert(s);
		}
		long long res=0;
		for(int i=0;i<N;++i){
			int num=query(a[i]);
			if(num>res)res=num;
		}
		printf("%lld\n",res);
	}
	return 0;
}
