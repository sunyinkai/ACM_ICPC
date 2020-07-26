t=int(input())
for i in range(0,t):
    s=input()
    if s.endwith("po"):
        print("FILIPINO")
    elif s.endswith("desu") or s.endwith("masu"):
        print("JAPANESE")
    elif s.endswith("mnida"):
        print("KOREAN")
