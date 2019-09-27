#include<cstdio>
#include<cstdlib>
#include<ctime>
const int MAXN=1e5+7;
int a[MAXN];
void swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

//knuth洗牌算法
void shuffle(int N){
    srand(time(NULL));
    for(int i=N;i>=1;--i){
        int x=rand()%N+1;
        swap(a[i],a[x]);
    }
}

void sort(int l,int r){
    if(l>=r)return;
    int i=l,j=r;
    while(i<j){
        while(a[j]>=a[l]&&i<j)j--;
        while(a[i]<=a[l]&&i<j)i++;
        swap(a[i],a[j]);
    }
    swap(a[l],a[i]);
    sort(l,i);
    sort(i+1,r);
}
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&a[i]);
    }
    shuffle(N);
    sort(1,N);
    for(int i=1;i<=N;++i)
        printf("%d\n",a[i]);
    return 0;
}
