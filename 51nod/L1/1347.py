s=input()
l=len(s)
if s[:l//2] == s[l//2:] :
	print("YES")
else :
	print("NO")
