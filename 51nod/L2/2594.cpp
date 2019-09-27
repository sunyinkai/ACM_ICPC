//tag: recursive
#include<cstdio>
#include<cstring>
const int MAXN=57;
char a[MAXN];

int solve(int s,int t){
 //   printf("s:%d,t:%d\n",s,t);
    if(t-s==1)return 1;// ()返回1
    int val=0;
    int ans=0;
    int prev=s;
    for(int i=s;i<=t;++i){
        if(a[i]=='(')++val;
        else --val;
        if(val==0){
            if(prev==s&&i==t){
                ans+=solve(prev+1,i-1)*2;
            }else{
                ans+=solve(prev,i);
            }
            prev=i+1;
        }
    }
    return ans;
}

int main(){
    scanf("%s",a);
    int len=strlen(a);
    printf("%d\n",solve(0,len-1));
    return 0;
}
