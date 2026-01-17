import sys
sys.setrecursionlimit(1000000)
S = sys.stdin.readline().rstrip()
T = sys.stdin.readline().rstrip()

def is_possible(curS):
    global T
    if len(curS) > len(T):
        return 0
    if curS == T:
        return 1
    
    case1 = curS + 'A'
    case2 = (curS + 'B')[::-1]

    if case1 in T or case1[::-1] in T:
        if is_possible(case1):
            return 1
    if case2 in T or case2[::-1] in T:
        if is_possible(case2):
            return 1
    
    return 0

print(is_possible(S))