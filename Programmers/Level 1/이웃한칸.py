def solution(board, h, w):
    answer = 0
    n = len(board)
    cur_clr = board[h][w]
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    
    for dir in directions:
        near_h, near_w = h + dir[0], w + dir[1]
        if 0 <= near_h < n and 0 <= near_w < n and board[near_h][near_w] == cur_clr:
            answer += 1
    return answer
