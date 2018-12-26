#include<bits/stdc++.h>
using namespace std;
const int MAXN=600;
char s[MAXN];
int len;
bool check(){
    if(s[0]=='+'||s[0]=='*'||s[len-1]=='*'||s[len-1]=='+')return false;
    int statu=0;
    int i=0;
    while(i<len){
      //  cout<<"in"<<endl;
        switch(statu){
            case 0:{
                if(s[i]=='+'||s[i]=='*')statu=1;
                else if(s[i]=='0')statu=2;
                else statu=3;
                break;
            }
            case 1:{
                if(s[i]=='+'||s[i]=='*')return false;
                if(s[i]=='0')statu=2;
                else statu=3;
                break;
            }
            case 2:{
                if(s[i]=='+'||s[i]=='*'){
                statu=1;
             //   cout<<"in"<<s[i]<<endl;
                }
                else return false;
                break;
            }
            case 3:{
                if(s[i]=='+'||s[i]=='*')statu=1;
                break;
            }
        }
        i++;
            //cout<<statu<<endl;
        
    }
    return true;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        len=strlen(s);
        if(s[0]=='?')s[0]='1';
        for(int i=1;i<len;i++){
            if(s[i]=='?'){
                if(s[i-1]!='0')s[i]='1';
                else{
                    if(i-2<0||s[i-2]=='+'||s[i-2]=='*')s[i]='+';
                    else s[i]='1';
                }
            }
        }
        //cout<<"ok"<<endl;
        //cout<<s<<endl;
        if(check()){
            printf("%s\n",s);
        }
        else printf("IMPOSSIBLE\n");
    }
}