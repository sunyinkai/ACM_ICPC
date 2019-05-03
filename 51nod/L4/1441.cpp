//tag: math
#include<cstdio>
#include<cstring>
const int MAXN=5e6+7;
//ctrl + D EOF
//不能关闭同步
//只能读入int
const int BUF_SIZE=40960;
struct f {
    int cur, eof;
    char buf[BUF_SIZE];
    char next_char() {
        if (cur == BUF_SIZE) {
            if (eof) return -1;
            int bytes = fread(buf, 1, BUF_SIZE, stdin);
            if (bytes < BUF_SIZE) {
                memset(buf + bytes, -1, BUF_SIZE - bytes);
                buf[bytes] = -1;
                eof = 1;
            }
            cur = 0;
        }
        return buf[cur++];
    }
    int next_int() {
        int x = 0;
        char ch = next_char();
        while (ch < '0' || ch > '9') {
            if (ch == -1) return 0;
            ch = next_char();
        }
        while (ch >= '0' && ch <= '9') {
            x = x*10 + ch - '0';
            ch = next_char();
        }
        return x;
    }
} IO = {BUF_SIZE,};
long long f[MAXN];//f[i]:1*2*..i的因子个数
int  isok[MAXN];

void init(){
    memset(isok,-1,sizeof(isok));
    for(int i=2;i<MAXN;++i){
        if(isok[i]){
            ++f[i];
            for(int j=2*i;j<MAXN;j+=i){
                int t=j;
                while(t%i==0){
                    ++f[j];
                    t/=i;
                }
                isok[j]=0;
            }
        }
    }
    for(int i=1;i<MAXN;++i)
        f[i]+=f[i-1];
}

int main(){
    int T;scanf("%d",&T);
    init();
    while(T--){
        int a,b;
        a=IO.next_int();
        b=IO.next_int();
      //  printf("f[a]:%lld,f[b]:%lld\n",f[a],f[b]);
        printf("%lld\n",f[a]-f[b]);
    }
    return 0;
}
