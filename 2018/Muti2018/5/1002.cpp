#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int maxVal,minVal,num,len;
char s[13];
void dfs(int k,int now,int val){
	//printf("k=%d,now=%d,val=%d\n",k,now,val);
	if(k==0||now==len){
		maxVal=max(maxVal,val);
		return ;
	}
	int a[13],top=0;
	int tmp=val;
	while(val){
		a[top++]=val%10;
		val/=10;
	}
	reverse(a,a+top);
	int mx=-1;
	for(int i=now;i<top;++i){
		if(mx==-1||a[i]>a[mx])mx=i;
	}
	if(a[now]==a[mx]){
		dfs(k,now+1,tmp);
	}

	for(int i=now;i<top;++i){
		if(a[i]==a[mx]){
			swap(a[now],a[i]);
			int to=0;
			for(int i=0;i<top;++i){
				to=to*10+a[i];
			}
			swap(a[i],a[now]);//换回来
			dfs(k-1,now+1,to);
		}
	}
}//big


void dfs2(int k,int now,int val){
	//printf("k=%d,now=%d,val=%d\n",k,now,val);
	if(k==0||now==len){
		minVal=min(minVal,val);
		return ;
	}
	int a[13],top=0;
	int tmp=val;
	while(val){
		a[top++]=val%10;
		val/=10;
	}
	reverse(a,a+top);
	int mx=-1;
	if(now==0){
		//选一个非０的最小值
		for(int i=now;i<top;++i){
			if(a[i]==0)continue;
			if(mx==-1||a[i]<a[mx])mx=i;
		}
	}else{
		for(int i=now;i<top;++i){
			if(mx==-1||a[i]<a[mx])mx=i;
		}
	}
	
	if(a[now]==a[mx]){
		dfs2(k,now+1,tmp);
	}

	for(int i=now;i<top;++i){
		if(a[i]==a[mx]){
		/*	if(now==0){
				printf("i=%d\n",i);
			}*/

			swap(a[now],a[i]);
			int to=0;
			for(int j=0;j<top;++j){
				to=to*10+a[j];
			}

			//printf("to=%d\n",to);
			swap(a[i],a[now]);//换回来
			dfs2(k-1,now+1,to);
		}
	}
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int k;
        scanf("%s%d",s,&k);
		char tmp[13];
		len=strlen(s);
		for(int i=0;i<13;++i)tmp[i]=s[i];
		int val=0;
		for(int i=0;i<len;++i){
			val=val*10+s[i]-'0';
		}

		maxVal=minVal=val;
		dfs(k,0,val);
		dfs2(k,0,val);
		printf("%d %d\n",minVal,maxVal);
	}

	return 0;
}
