#include<cstdio>
//fread是一个函数。从一个文件流中读数据，最多读取count个元素，每个元素size字节，如果调用成功返回实际读取到的元素个数，如果不成功或读到文件末尾返回 0
const int SIZE=2;
inline char nc(){
    static char buf[SIZE],*p1=buf,*p2=buf;
    if(p1==p2) p2=(p1=buf)+fread(buf,1,SIZE,stdin);
    return p1==p2?EOF:*p1++;
}

int read(){
    int num=0;
    char ch;
    while((ch=getchar())>='0'&&ch<='9')num=num*10+ch-'0';
    return num;
}

int main(){
    for(int i=0;i<5;++i){
        int x=read();
        printf("%d\n",x);
    }
    return 0;
}
