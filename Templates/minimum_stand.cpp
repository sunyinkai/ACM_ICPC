//最小表示法 hiho1983
//求字符串的最小表示
#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)

const int MAXN=107;
char s[MAXN];
int solve(int n){
int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
      if (s[(i + k) % n] == s[(j + k) % n]) {
        k++;
      } else {
        s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
        if (i == j) i++;//如果跳转过去两个相等,任意增加一个
        k = 0;
        printf("i,j =%d,%d\n",i,j);
      }
    }
    i = min(i, j);
}
int main(){
    scanf("%s",s);
    printf("%d\n",solve(strlen(s)));
    return 0;
}
