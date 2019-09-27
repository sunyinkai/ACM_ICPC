#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+7;
char s[MAXN];
char x[MAXN],y[MAXN];
int m,n;
int visit[MAXN];
int len;
int Min[MAXN];
bool check(const char*x,int m){
 //   for(int i=0;i<m;++i)
  //      putchar(x[i]);
  //  printf("\n");
    for(int i=1;i<m;++i){
        if(x[i]<x[i-1])return false;
    }
    return true;
}
void init(){
    for(int i=len-1;i>=0;--i){
        if(i==len-1)Min[i]=s[i];
        else Min[i]=min((int)s[i],Min[i+1]);
    }
}

int isok(int pos,char ch){
 //   printf("ch:%c,pos:%d,Min[pos]:%c\n",ch,pos,Min[pos]);
    return ch<=Min[pos];
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&len);
        scanf("%s",s);
        bool hasAns=false;
        init();
        for(int i='0';i<='9';++i){
            m=n=0;
            for(int j=0;j<len;++j){
                visit[j]=0;//init
                if(s[j]<=i){
                    if(s[j]<i)x[m++]=s[j],visit[j]=1;
                    else{
                        if(isok(j,s[j]))x[m++]=s[j],visit[j]=1;
                        else y[n++]=s[j];
                    }
                }
                else y[n++]=s[j];
            }
            if(check(x,m)&&check(y,n)){
                for(int j=0;j<len;++j){
                    if(visit[j])printf("1");
                    else printf("2");
                }
                hasAns=true;
                break;
            }
        }
        if(!hasAns)printf("-") ;
        printf("\n");
    }
    return 0;
}
