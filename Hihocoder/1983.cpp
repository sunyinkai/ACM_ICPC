#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int MAXN=1e5+7;
char s[MAXN];
int solve(int len){
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        if(s[(i+k)%len]==s[(j+k)%len])++k;
        else{

            s[(i+k)%len]>s[(j+k)%len]?i=i+k+1:j=j+k+1;
            if(i==j)++i;
            k=0;
        }
    }
    return min(i,j);
}
int main(){
    scanf("%s",s);
    int len=strlen(s);
    int val=solve(len);
    for(int i=val,cnt=0;cnt<len;++cnt){
        printf("%c",s[(i+cnt)%len]);
    }
    printf("\n");
    return 0;
}
