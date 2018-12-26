#include<cstdio>
#include<cstring>
#include<cmath>

const int MAXN=1e5+7;
long long power[50];
void init(){ 
	power[0]=1;
	for(int i=1;i<50;++i)
		power[i]=(long long)power[i-1]*2;
}
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

long long sum[MAXN];
inline long long sigma(long long a,long long b){ 
	return (a+b)*(b-a+1)/2;
}

int main(){ 
	init();
	int T;T=IO.next_int();
	while(T--){ 
		int N;N=IO.next_int();
		for(int i=1;i<=N;++i)sum[i]=0;
		for(int i=1;i<=N;++i){ 
			int x;x=IO.next_int();
			sum[i]=sum[i-1]+x;
		}

		sum[N+1]=sum[N];
		long long res=0;
		for(int i=1;i<=N;++i){ 
			int prev=i;
			int up;
			if(sum[N]-sum[i-1]!=0) up=(int)log2(sum[N]-sum[i-1])+1;
			else  up=34;
			for(int k=1;k<=up;++k){ 
				int lo=prev-1,hi=N+1;
				while(hi-lo>1){ 
					int mid=(hi+lo)/2;
					if(sum[mid]-sum[i-1]>=power[k])hi=mid;
					else lo=mid;
				}

				long long cnt=hi-1 -prev +1;
				long long t;
				t=(k-1 + 1)*(i*cnt+sigma(prev,hi-1));
				res+=t;
				if(hi==N+1)break;
				prev=hi;
			}
		}

		printf("%lld\n",res);
	}
	return 0;
}
