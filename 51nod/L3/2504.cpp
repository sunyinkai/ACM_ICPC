//tag: two_pointer
#include<cstdio>
#include<cstring>
const int MAXN=5e4+7;
char s[MAXN],t[MAXN];
bool isok(const char*s,const char*t){
    int len_s=strlen(s),len_t=strlen(t);
    int i=0,j=0;
    while(i<len_s&&j<len_t){
        if(s[i]==t[j])++i,++j;
        else ++i;
    }
    return j==len_t;
}
int main(){
    scanf("%s",s);
    int N;scanf("%d",&N);
    int ans=0;
    for(int i=0;i<N;++i){
        scanf("%s",t);
        if(isok(s,t))++ans;
    }
    printf("%d\n",ans);
    return 0;
}

