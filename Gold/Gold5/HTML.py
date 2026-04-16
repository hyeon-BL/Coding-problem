import sys

line_cnt = 0
while True:
	raw = sys.stdin.readline()
	if not raw:
		break
	line = raw.rstrip().split()
	for word in line:
		if word == "<br>":
			print()
			line_cnt = 0
		elif word == "<hr>":
			if line_cnt != 0: print()
			print("-" * 80)
			line_cnt = 0
		else:
			if line_cnt == 0:
				print(word, end="")
				line_cnt = len(word)
			elif line_cnt + 1 + len(word) > 80:
				print()
				print(word, end="")
				line_cnt = len(word)
			else:
				print(" " + word, end="")
				line_cnt += 1 + len(word)

