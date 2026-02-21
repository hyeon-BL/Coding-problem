import sys
sys.setrecursionlimit(10**6)
L, C = map(int, sys.stdin.readline().split())
possible = list(sys.stdin.readline().split())
possible.sort()

def is_correct(password):
    consonants = 0
    vowels = 0
    for e in password:
        if e == 'a' or e == 'e' or e == 'i' or e == 'o' or e == 'u':
            vowels += 1
        else:
            consonants += 1
    if vowels >= 1 and consonants >= 2:
        return True
    else:
        return False

def backtrack(start, password):
    if (len(password) == L):
        if is_correct(password):
            print("".join(password))
        return

    for i in range(start, C):
        password.append(possible[i])
        backtrack(i + 1, password)
        password.pop()

backtrack(0, [])
