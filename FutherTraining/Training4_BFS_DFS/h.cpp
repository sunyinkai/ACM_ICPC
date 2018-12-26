#include<cstdio>
#include<cstring>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;
const int MAXN=2e5+7;
struct node{
	char s[50];
	int num,step;
}no[MAXN];
unordered_map<int,int>mp;
queue<node>q;
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
char getChar(int x,int y){
	if(x==1&&y==0)return 'u';
	if(x==-1&&y==0)return 'd';
	if(x==0&&y==1)return 'l';
	if(x==0&&y==-1)return 'r';
}
void init(){
	int tot=1;
	memset(no[tot].s,0,sizeof(no[tot].s));
	no[tot].num=123456780;
	no[tot].step=0;
	q.push(no[tot]);
	mp[123456780]=1;++tot;
	while(!q.empty()){
		node top=q.front();q.pop();
		int val=top.num;
		int a[10],pos;
		for(int i=8;i>=0;--i){
			a[i]=val%10;
			if(a[i]==0)pos=i;
			val/=10;
		}
		int x=pos/3,y=pos%3;
		for(int i=0;i<4;++i){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<3&&ny>=0&&ny<3){
				int nextPos=nx*3+ny;
				swap(a[nextPos],a[pos]);
				int nextNum=0;
				for(int i=0;i<=8;++i)nextNum=nextNum*10+a[i];
				swap(a[nextPos],a[pos]);
				if(mp[nextNum])continue;

				mp[nextNum]=tot;
				no[tot].num=nextNum;
				strcpy(no[tot].s, top.s);
				no[tot].s[top.step]=getChar(dx[i],dy[i]);
				no[tot].step=top.step+1;
				q.push(no[tot]);
				++tot;
			}
		}
	}
	//printf("tot=%d\n",tot);
}
int main(){
	init();
	char s[30];
	while(fgets(s,30,stdin)!=NULL){
		int res=0;
		int Len=strlen(s);
		for(int i=0;i<Len;++i){
			if(s[i]=='x')res=res*10+0;
			else if(s[i]>='0'&&s[i]<='9')res=res*10+s[i]-'0';
			else continue;
		}
		if(mp[res]==0){
			printf("unsolvable\n");
			continue;
		}
		int len=strlen(no[mp[res]].s);
		for(int i=len-1;i>=0;i--)printf("%c",no[mp[res]].s[i]);
		printf("\n");
	}
	return 0;
}
