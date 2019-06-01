//tag: math
#include<cstdio>
int main(){
        int N;scanf("%d",&N);
        int x=N-1;
        int ans=0;
        for(int i=1;i*i<=x;++i){
            if(x%i==0){
                ++ans;
                if(x/i!=i)++ans;
            }
        }
        printf("%d\n",ans);
    return 0;
}
