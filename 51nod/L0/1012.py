def gcd(A,B):
	if B:
		return gcd(B,A%B)
	else:
		return A

if __name__=='__main__':
	A,B=map(int,input().strip().split(' '))
	print(A//gcd(A,B)*B)
