def conv_sec(time):
    minute, second = map(int, time.split(":"))
    res = minute * 60 + second
    return res

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    cur = conv_sec(pos)
    op_s_sec = conv_sec(op_start)
    op_e_sec = conv_sec(op_end)
    total_sec = conv_sec(video_len)
    for command in commands:
        if op_s_sec <= cur <= op_e_sec:
            cur = op_e_sec
        if command == "next":
            cur = min(cur + 10, total_sec)
        elif command == "prev":
            cur = max(cur - 10, 0)
        if op_s_sec <= cur <= op_e_sec:
            cur = op_e_sec
    answer = f"{cur//60:0>2}:{cur%60:0>2}"
    return answer