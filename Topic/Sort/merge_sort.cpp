#include<cstdio>
const int MAXN=1e5+7;
int a[MAXN];
int tmp[MAXN];
void sort(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    sort(l,mid);
    sort(mid+1,r);
    int i=l,j=mid+1;
    int tot=0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])tmp[tot++]=a[i],i++;
        else tmp[tot++]=a[j],j++;
    }
    while(i<=mid)tmp[tot++]=a[i],i++;
    while(j<=r)tmp[tot++]=a[j],j++;
    for(int i=l;i<=r;++i)a[i]=tmp[i-l];
}
int main(){
    int N;scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&a[i]);
    }
    sort(1,N);
    for(int i=1;i<=N;++i)
        printf("%d\n",a[i]);
    return 0;
}
