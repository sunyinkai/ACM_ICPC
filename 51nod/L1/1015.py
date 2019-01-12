M=int(input())
while True:
	len_x=len(str(M))
	ans=0
	x=M
	while x:
		ans+=(x%10)**len_x
		x//=10
	if ans == M:
		break
	M=M+1
print(M)
