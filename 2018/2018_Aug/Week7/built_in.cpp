#include<cstdio>
#include<cstring>
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

int main(){
	//都为unsigned
	freopen("in.txt","r",stdin);
	int res=0;
	/*for(int i=0;i<=(int)1e7;++i){

		int x=IO.next_int();
		int val=__builtin_popcount(x);//1e8 0.4s
		res+=val;
	}*/

	for(int i=0;i<=(int)2e7;++i){
		//printf("%d\n",__builtin_ffs(x));//返回最后一个1所在的位置
		//printf("%d\n",__builtin_popcount(x));//返回x中1的个数
		int x=IO.next_int();
		int val=__builtin_popcount(x);//1e8 0.4s
		/*int val=0;
		for(int j=0;j<30;++j){// 30次 1e8 7s
			if(x&(1<<j))++val;// 10次 1e8 0.9s
		}*/
		res+=val;
	}
	printf("%d\n",res);
	return 0;
}
