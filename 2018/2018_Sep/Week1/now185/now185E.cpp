#include<cstdio>
#include<cstring>
const int MAXN=5e6+7;
char s[MAXN];
int q[MAXN],top=0;
//首先注意到抵消后,最后答案一定是 ))))((((这种形式
//一次交换操作,最多可以抵消两个 ))(( -> ()()
int main(){
    int len;scanf("%d",&len);
    scanf("%s",s);
    for(int i=0;i<len;++i){
        if(s[i]=='(')++top;
        else if(s[i]==')'&&top!=0)--top;
    }
    printf("%d\n",(top+1)/2);
    return 0;
}
