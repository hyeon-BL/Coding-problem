import sys
N = int(sys.stdin.readline())
exts = {}
for _ in range(N):
    file = sys.stdin.readline().rstrip().split('.')
    if file[1] not in exts:
        exts[file[1]] = 1
    else:
        exts[file[1]] += 1
for key in sorted(exts.keys()):
    print(key, exts[key])