//消成上三角矩阵
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_BASE=62;
const int MAXN=1e5+7;
typedef long long LL;
LL a[MAXN],b[MAXN];
//O(N*K)
bool insert(LL val){//插入的这个数是否已经能被张成
	for(int i=MAX_BASE;i>=0;--i){
		if(val&(1LL<<i)){
			if(!b[i]){b[i]=val;break;}
			val^=b[i];
		}
	}
	return val>0;
}

LL qmax(){//从高位往地位贪心.如3,1
    long long res=0;
    for(int i=MAX_BASE;i>=0;i--)if((res^b[i])>res)res^=b[i];
    return res;
}

long long qmin(){//询问最小值
    for(int i=0;i<=MAX_BASE;i++)if(b[i])return b[i];
	return 0;
}

long long query(int k){//询问第k大,将k转化为2进制,将b化为code2那种形式
    long long tmp[MAX_BASE+1],res=0;int cnt=0;
    for(int i=0;i<=MAX_BASE;i++){
        for(int j=i-1;j>=0;j--)if(b[i]&(1LL<<j))b[i]^=b[j];
        if(b[i])tmp[cnt++]=b[i];
    }
    for(int i=0;i<cnt;i++)if(k&(1LL<<i))res^=tmp[i];
    return res;
}

bool isok(LL val){//能不能张成val
	for(int i=MAX_BASE;i>=0;--i){
		if(val&(1LL<<i)){
			if(!b[i])return 0;
			val^=b[i];
		}
	}
	return 1;
}


void print(){
	for(int i=MAX_BASE;i>=0;--i){
		long long val=b[i];

		int x[MAX_BASE+5];
		for(int j=0;j<=MAX_BASE;++j){
			x[j]=val%2;
			val/=2;
		}
		reverse(x,x+MAX_BASE+1);
		for(int j=0;j<=MAX_BASE;++j)
			printf("%d",x[j]);
		printf("\n");
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int N;scanf("%d",&N);
	for(int i=0;i<N;++i){
		long long x;scanf("%lld",&x);
		insert(x);
	}
	print();
	/*int Q;scanf("%d",&Q);
	while(Q--){
		long long x,y;scanf("%lld%lld",&x,&y);
		if(isok(x^y))printf("YES\n");
		else printf("NO\n");
	}*/
	return 0;
}
