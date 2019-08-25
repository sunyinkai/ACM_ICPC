#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=11;
const int INF=1e9+7;
int a[MAXN];
bool isok(){
    int b[MAXN*2];
    for(int i=0;i<10;++i){
        b[i]=a[i];
        b[10+i]=b[i];
    }

    int max_sum=0,min_sum=INF;
    for(int i=0;i<=10;++i){
        int val=0;
        for(int j=i;j<5+i;++j){
            val+=b[j];
        }
        max_sum=max(max_sum,val);
        min_sum=min(min_sum,val);
    }
    return max_sum-min_sum<=1;
}
int main(){
    for(int i=0;i<10;++i)a[i]=i+1;

    do{
        for(int i=0;i<10;++i){
            if(isok()){
                for(int j=0;j<10;++j)
                    printf("%d ",a[j]);
                printf("\n");
                return 0;
            }
        }
    }while(next_permutation(a,a+10));
    return 0;
}
