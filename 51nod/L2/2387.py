#tag: simple
n,c,d=map(int,input().strip().split())
l=list(map(int,input().strip().split()))
l.sort()
num=d*2+(c-d)
ans,cnt=0,0
for x in l:
    if ans+x<=num:
        cnt+=1
        ans+=x
    else:
        break
print(cnt)
