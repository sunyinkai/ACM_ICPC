#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAXN=1e5+7;
int Next[MAXN],extand[2*MAXN];
char s[MAXN*2],t[MAXN];
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

int main(){
	int T;scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%s",t);
		int lenT=strlen(t);
		for(int i=0;i<lenT;++i)s[i]=t[i];
		for(int i=0;i<=lenT;++i)s[i+lenT]=t[i];
		GetExtand(s,t);
		int x=0,y=0,z=0;
		for(int i=0;i<lenT;++i){
			if(extand[i]==lenT){
				if(y==0)++y;
				else break;
			}
			else{
				int val=extand[i];
				if(s[i+val]<s[val])++x;//less
				else ++z;//big
			}
		}
		printf("Case %d: %d %d %d\n",test,x,y,z);
	}
	return 0;
}
