#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=107;
char s[MAXN];
int main(){
    scanf("%s",s);
    if(strcmp(s,"0")==0){
        printf("0\n");
        return 0;
    }
    int len=strlen(s);
    int ans=0;
    ans+=(len+1)/2;
    int cnt=0;
    for(int i=0;i<len;++i){
        if(s[i]=='0')++cnt;
    }
    if((len&1)&&cnt==len-1)--ans;
    if(ans<=0)ans=0;
    printf("%d\n",ans);
    return 0;
}
