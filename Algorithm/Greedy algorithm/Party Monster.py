import sys
T = int(sys.stdin.readline())
for _ in range(T):
	n = int(sys.stdin.readline())
	s = sys.stdin.readline()
	open_cnt = s.count("(")
	close_cnt = s.count(")")
	if open_cnt != close_cnt:
		print("NO")
	else:
		print("YES")

