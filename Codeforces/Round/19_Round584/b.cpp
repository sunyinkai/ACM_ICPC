#include<cstdio>
const int MAXN=107;
char s[MAXN];
char change(char ch){
    if(ch=='0')return '1';
    else return '0';
}
int a[MAXN],b[MAXN];
int main(){
    int N;scanf("%d",&N);
    scanf("%s",s);
    int ans=0;
    for(int i=0;i<N;++i){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int t=0;t<=10000;++t){
        for(int i=0;i<N;++i){
            if(t>=b[i]&&(t-b[i])%a[i]==0){
                s[i]=change(s[i]);
            }
        }
        int cnt=0;
        for(int i=0;i<N;++i)
            if(s[i]=='1')++cnt;
        if(cnt>ans)ans=cnt;
    }
    printf("%d\n",ans);
    return 0;
}
