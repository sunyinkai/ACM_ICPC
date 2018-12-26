N=int(input())
mid=N//2
l=[]
while N:
	N=N-1
	x=int(input())
	l.append(x)
l.sort()
ans=0
mid=l[mid]
for i in l:
	ans+=abs(mid-i)
print(ans)
