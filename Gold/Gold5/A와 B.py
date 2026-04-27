import sys
S = sys.stdin.readline().strip()
T = list(sys.stdin.readline().strip())

target = T
while len(target) > len(S):
	if target[-1] == 'A':
		target.pop()
	elif target[-1] == 'B':
		target.pop()
		target.reverse()
	else:
		break

if "".join(target) == S:
	print(1)
else:
	print(0)
