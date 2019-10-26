#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int q;scanf("%d",&q);
    while(q--){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        int max_cnt=(a+b+c)/3;
        printf("%d\n",min(max_cnt,min(a,b)));
    }
    return 0;
}
