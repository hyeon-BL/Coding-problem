import sys
wheels = [sys.stdin.readline().rstrip() for _ in range(4)]
K = int(sys.stdin.readline())

def rotate_wheel(wheel, wise):
	rotated = ""
	if wise == 1:
		rotated += wheel[-1]
		rotated += wheel[:-1]
	else:
		rotated += wheel[1:]
		rotated += wheel[0]
	return rotated

def is_connected():
	connected = []
	if wheels[0][2] != wheels[1][6]:
		connected.append(1)
	if wheels[1][2] != wheels[2][6]:
		connected.append(2)
	if wheels[2][2] != wheels[3][6]:
		connected.append(3)
	return connected

for _ in range(K):
	target, wise = map(int, sys.stdin.readline().split())
	connected = is_connected()
	if target == 1:
		wheels[0] = rotate_wheel(wheels[0], wise)
		if 1 in connected:
			wheels[1] = rotate_wheel(wheels[1], -wise)
			if 2 in connected:
				wheels[2] = rotate_wheel(wheels[2], wise)
				if 3 in connected:
					wheels[3] = rotate_wheel(wheels[3], -wise)
	elif target == 2:
		wheels[1] = rotate_wheel(wheels[1], wise)
		if 1 in connected:
			wheels[0] = rotate_wheel(wheels[0], -wise)
		if 2 in connected:
			wheels[2] = rotate_wheel(wheels[2], -wise)
			if 3 in connected:
				wheels[3] = rotate_wheel(wheels[3], wise)
	elif target == 3:
		wheels[2] = rotate_wheel(wheels[2], wise)
		if 2 in connected:
			wheels[1] = rotate_wheel(wheels[1], -wise)
			if 1 in connected:
				wheels[0] = rotate_wheel(wheels[0], wise)
		if 3 in connected:
			wheels[3] = rotate_wheel(wheels[3], -wise)
	else:
		wheels[3] = rotate_wheel(wheels[3], wise)
		if 3 in connected:
			wheels[2] = rotate_wheel(wheels[2], -wise)
			if 2 in connected:
				wheels[1] = rotate_wheel(wheels[1], wise)
				if 1 in connected:
					wheels[0] = rotate_wheel(wheels[0], -wise)
score = 0
for i in range(4):
	if int(wheels[i][0]):
		score += 2 ** i
print(score)
