#include<cstdio>
const int MAXN=107;
int q[MAXN],N,top;
int is_ok(int x){
    for(int i=0;i<top;++i)
        if(q[i]==x)return 1;
    return 0;
}

int main(){
    scanf("%d",&N);
    int ans=0;
    for(int i=0;i<N;++i){
        int x;scanf("%d",&x);
        q[top++]=x;
    }

    for(int i=1;i<MAXN&&top;++i){
        if(is_ok(i)){
            int prev=top;
            top=0;
            for(int k=0;k<prev;++k){
                int x=q[k];
                if(x%i!=0)q[top++]=x;
            }
            if(top!=prev)++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
