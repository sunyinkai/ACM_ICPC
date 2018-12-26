#include<cstdio>
#include<cstring>
const int maxn = 2000, maxlen = 1e6+10;//sqrt(1e6)

struct Block_List{
    struct Node{
        char buff[maxn];
        int size, next;
        void init(){
            size = 0, next = -1;
            memset(buff,0,sizeof(buff));
        }
    }List[maxn];
    int head, tot;

    void init(char s[]){
        head = tot = 0;
        List[tot++].init();
        int cur = 0;
        for(int i = head; s[cur]; i = List[i].next){
            for(int j = 0; j < maxn && s[cur]; j++,cur++){
                List[i].buff[j] = s[cur];
                List[i].size++;
            }
            if(s[cur]){
                List[tot].init();
                List[i].next = tot++;
            }
        }
        for(int i = head; i!=-1; i = List[i].next)
            if(List[i].size==maxn)Split(i);
    }

    void Split(int id){
        List[tot].init();
        for(int i = maxn/2; i < maxn; i++){
            List[tot].buff[i-maxn/2] = List[id].buff[i];
            List[tot].size++;
            List[id].buff[i] = 0;
            List[id].size--;
        }
        List[tot].next = List[id].next;
        List[id].next = tot++;
    }

    void Insert(int pos, char val){
        int i;
        for(i = head; pos > List[i].size && List[i].next != -1; i = List[i].next)
            pos -= List[i].size;
        if(pos >= List[i].size)List[i].buff[List[i].size] = val;
        else {
            for(int j = List[i].size; j > pos; j--)
                List[i].buff[j] = List[i].buff[j-1];
            List[i].buff[pos] = val;
        }
        List[i].size++;
        if(List[i].size==maxn)Split(i);
    }

    char Find(int pos){
        int i;
        for(i = head; pos > List[i].size; i = List[i].next)
            pos -= List[i].size;
        return List[i].buff[pos-1];
    }
}Meow;

char op[2], buff[maxlen];
int pos;

int main(){
    scanf("%s",buff);
    Meow.init(buff);
    int n;  scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",op);
        if(op[0]=='I'){
            scanf("%s%d",buff,&pos);
            Meow.Insert(pos-1,buff[0]);
        }else {
            scanf("%d",&pos);
            printf("%c\n",Meow.Find(pos));
        }
    }
    return 0;
}
