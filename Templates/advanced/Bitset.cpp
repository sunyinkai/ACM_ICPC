#include<cstdio>
#include<bitset>
#include<iostream>
using namespace std;
const int MAXN=10;
//实现原理:将32/64个bit压为一个数,从而使常数/32或/64
int main(){
    bitset<MAXN>bt;
    // bt[0]=1;
    // bt[1]=1;
    //high.....low
    // cout<<bt<<endl;//输出bitset所有
    // bt.set();//将全部置位1
    // bt.reset();//全部置为0
    // bt.set(6,1);//将某位置为1,等价于bit[6]=1;
    bt.set();
    cout<<(bt<<2)<<endl;//整体向左移动两位补0
    bt.reset();
    bt.set();
    cout<<~( bt>>2)<<endl;//整体右移2位,补0
    return 0;
}