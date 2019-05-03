//tag: slide_window
#include<cstdio>
#include<cstring>
const int MAXN=1e4+7;
char s1[MAXN],s2[MAXN];
int cnt[500];
int ans[500];
int main(){
    scanf("%s%s",s1,s2);
    int len_1=strlen(s1),len_2=strlen(s2);
    //find the alpha count of s1
    for(int i=0;i<len_1;++i)
        cnt[s1[i]]++;
    //slide the window
    bool isok=false;
    int num=0;
    for(int i=0;i<len_2;++i){
        ans[s2[i]]++;
        ++num;
        if(num==len_1){
            bool valid=true;
            for(int j='a';j<='z';++j)
                if(ans[j]!=cnt[j])valid=false;
            if(valid)isok=true;
            --ans[s2[i-len_1+1]];
            --num;
        }
    }

    printf(isok?"True\n":"False\n");
    return 0;
}
