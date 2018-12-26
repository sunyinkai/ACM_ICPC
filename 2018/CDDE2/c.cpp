#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAXN=1e6+7;
const long long mod=1e9+7;
int Next[MAXN],extand[MAXN];
char s[MAXN],t[MAXN];
void GetNext(const char *T){
     int len=strlen(T),a=0;
     Next[0]=len;
     while(a<len-1 && T[a]==T[a+1]) a++;
     Next[1]=a;
     a=1;
     for(int k=2;k<len;k++){
         int p=a+Next[a]-1,L=Next[k-a];
         if( (k-1)+L >= p){
             int j = (p-k+1)>0 ? (p-k+1) : 0;
             while(k+j<len && T[k+j]==T[j]) j++;
             Next[k]=j;
             a=k; 
         } 
         else
             Next[k]=L; 
     } 
} 
void GetExtand(const char *S,const char *T){
	//S文本串，T模式串
     GetNext(T);
     int slen=strlen(S),tlen=strlen(T),a=0; 
     int MinLen = slen < tlen ? slen : tlen;
     while(a<MinLen && S[a]==T[a]) a++;
     extand[0]=a;
     a=0;
     for(int k=1;k<slen;k++){
         int p=a+extand[a]-1, L=Next[k-a];
         if( (k-1)+L >= p){
             int j= (p-k+1) > 0 ? (p-k+1) : 0;
             while(k+j<slen && j<tlen && S[k+j]==T[j]) j++;
             extand[k]=j;
             a=k; 
         }
         else 
             extand[k]=L; 
     } 
} 

long long fast_pow(long long base,long long n){
	long long res=1;
	while(n){
		if(n&1)res=res*base%mod;
		base=base*base%mod;
		n/=2;
	}
	return res;
}

int visit[MAXN];
int main(){
	int N,M;scanf("%d%d",&N,&M);
	scanf("%s",s);
	int lenS=strlen(s);
	for(int i=0;i<=lenS;++i)
		t[i]=s[i];
	GetExtand(s,t);

	int now=-1;
	for(int i=0;i<M;++i){
		int x;scanf("%d",&x);
		x--;
		if(x>now){
			for(int i=x;i<x+lenS;++i){//?
				visit[i]=1;
			}
			now=x+lenS-1;
		}else{//x<=now
			int maxCommonLen=extand[lenS-1-(now-x)];
			int len=now-x+1;
	//		printf("the maxCommonLen=%d\n",maxCommonLen);
	//		printf("now=%d,len=%d\n",now,len);
			if(len!=maxCommonLen){
				printf("0\n");
				return 0;
			}
	//		printf("begin=%d,end=x+lenS-1=%d\n",x,x+lenS-1);
			for(int i=now;i<=x+lenS-1;++i)visit[i]=1;
			now=x+lenS-1;
	//		printf("after now=%d\n",now);
		}
	}
	int all=N;
	for(int i=0;i<N;++i)
		if(visit[i])--all;
	printf("%lld\n",fast_pow(26,all));
	return 0;
}
