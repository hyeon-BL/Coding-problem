import sys
criteria = [(1, 2, 3), (4, 5, 6), (7, 8, 9), (1, 4, 7), (2, 5, 8), (3, 6, 9), (1, 5, 9), (3, 5, 7)]

def check_win(grid, player):
    for a, b, c in criteria:
        if grid[a-1] == grid[b-1] == grid[c-1] == player:
            return True
    return False

while True:
	grid = sys.stdin.readline().rstrip()

	if grid == 'end':
		break

	cnt_O = 0
	cnt_X = 0
	for e in grid:
		if e == 'O':
			cnt_O += 1
		elif e == 'X':
			cnt_X += 1

	x_win = check_win(grid, 'X')
	o_win = check_win(grid, 'O')

	if x_win and not o_win:
		if cnt_X == cnt_O + 1: print('valid')
		else: print('invalid')
	elif o_win and not x_win:
		if cnt_X == cnt_O: print('valid')
		else: print('invalid')
	elif not x_win and not o_win:
		if cnt_X + cnt_O == 9 and cnt_X == 5 and cnt_O == 4: print('valid')
		else: print('invalid')
	else: # 둘 다 이긴 경우
		print('invalid')
