#include<cstdio>
#include<cstring>
const int MAXN=1e6+7;
int max[1007];
int SZ;
void init(){//初始化
	for(int i=0;i<n;++i){
		if(i%SZ==0||max[i/SZ]<a[i]){
			max[i/SZ]=a[i];
		}
	}
}
int query(int l,int r){//询问l,r最大值
	int res=a[l];
	for(int i=l;i<=r;){
		if(i%SZ==0&&i+SZ-1<=r){
			if(max[i/SZ]>res)res=max[i/SZ];
			i+=SZ;//跳跃SZ步
		}else{
			if(a[i]>res)res=a[i];
			i++;
		}
	}
	return res;
}
void update(int x,int val){
	a[x]=val;
	int l=x/SZ*SZ;
	int r=SZ+l;
	for(int i=l;i<r;++i){
		if(i%SZ==0||a[i]>max[i/SZ])max[i/SZ]=a[i];
	}
}
int main(){
	int N;scanf("%d",&N);
	SZ=sqrt(N);
	return 0;
}
