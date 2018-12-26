#include<cstdio>
#include<cstring>
const int MAXN=1e5+1;
int q[MAXN],top=0;
int isprime[MAXN];
bool isok(int num){
	int val=num;
	int tmp[7],tot=0;
	while(val){
		tmp[tot++]=val%10;
		val/=10;
	}
	reverse(tmp,tmp+tot);
	bool hasAn
	for(int k=1;k<(1<<tot);++k){
		int num=0;
		for(int i=0;i<tot;++i){
			if(k&(1<<i))num=num*10+tmp[i];
			if(isprime[num])
		}
	}

}

void init(){
	for(int i=2;i<MAXN;++i)isprime[i]=1;
	for(int i=2;i<MAXN;++i){
		if(isprime[i]){
			for(int j=2*i;j<MAXN;j+=i)isprime[j]=0;
		}
	}
	for(int i=2;i<MAXN;++i){
		if(isprime[i]){
			if(isok(i)){
				q[top++]=i;
			}
		}
	}
}

int main(){
	init();
	return 0;
}

