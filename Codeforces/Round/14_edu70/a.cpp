#include<cstdio>
#include<cstring>
const int MAXN=1e5+7;
char s[MAXN];
char t[MAXN];
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s%s",s,t);
        int len_s=strlen(s);
        int len_t=strlen(t);
        int id=0;
        for(int i=len_t-1;i>=0;--i){
            if(t[i]=='0'){
                ++id;
            }else{
                break;
            }
        }
        int ans=0;
        for(int i=len_s-1-id;i>=0;--i){
            if(s[i]=='1'){
                break;
            }else{
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
