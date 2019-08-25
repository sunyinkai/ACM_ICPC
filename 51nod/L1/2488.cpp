//tag: math
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long myabs(long long a){
    return a<0?-a:a;
}
int main(){
    long long a,b,c,d;scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    long long e,f,g,h;scanf("%lld%lld%lld%lld",&e,&f,&g,&h);
    long long x_1=myabs(c-a)+myabs(g-e);
    long long x_2=max(c,g)-min(a,e);
    long long y_1=myabs(d-b)+myabs(h-f);
    long long y_2=max(d,h)-min(b,f);
    long long uni=0;
    if(x_2>x_1)uni=0;
    else if(y_2>y_1)uni=0;
    else{
        uni=(x_1-x_2)*(y_1-y_2);
    }
    printf("%lld\n",(c-a)*(d-b)+(g-e)*(h-f)-uni);
    return 0;
}
