//tag: greedy
#include<cstdio>
#include<cstdlib>
#include<cmath>

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int N;scanf("%d",&N);
        int a[2]={0};
        int cnt[2]={0};
        int has_ans=1;

        for(int i=1;i<=N;++i){
            int x;scanf("%d",&x);
            int q[2],top=0;
            if(x>a[0])q[top++]=0;
            if(x>a[1])q[top++]=1;

            if(top==0){has_ans=false;break;}
            else if(top==1){
                cnt[q[0]]++;
                a[q[0]]=x;
            }else if(top==2){
                if(x-a[0]>x-a[1]){
                    cnt[1]++;
                    a[1]=x;
                }else if(x-a[0]<x-a[1]){
                    cnt[0]++;
                    a[0]=x;
                }else if(x-a[0]==x-a[1]){
                    if(cnt[0]<cnt[1])cnt[0]++,a[0]=x;
                    else cnt[1]++,a[1]=x;
                }
            }
        }
        if(has_ans)printf("%d\n",abs(cnt[0]-cnt[1]));
        else printf("-1\n");
    }
    return 0;
}
