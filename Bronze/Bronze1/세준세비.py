T = int(input())

while(T > 0):
    try:
        N, M = map(int, input().split())
    except ValueError:
        continue

    Sj = list(map(int, input().split()))
    Sb = list(map(int, input().split()))

    Sj.sort()
    Sb.sort()

    while Sj and Sb:
        if Sj[0] >= Sb[0]:
            Sb.pop(0)
        elif Sj[0] < Sb[0]:
            Sj.pop(0)
    if Sj:
        print("S")
    else:
        print("B")
    T -= 1