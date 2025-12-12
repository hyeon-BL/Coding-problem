import sys
sore_finger = int(sys.stdin.readline().strip())
remain_cnt = int(sys.stdin.readline().strip())

if sore_finger == 1:
    # 1번 손가락
    print(remain_cnt * 8)
elif sore_finger == 5:
    # 5번 손가락
    print(remain_cnt * 8 + 4)
else:
    # 2, 3, 4번 손가락은 주기적 움직임 (주기: 8)
    cycle = 2
    full_cycles = remain_cnt // cycle
    remainder = remain_cnt % cycle

    # 손가락 번호에 따라 주기 내에서의 위치 계산
    if sore_finger == 2:
        print(full_cycles * 8 + (0 if remainder == 0 else 6) + 1)
    elif sore_finger == 3:
        print(full_cycles * 8 + (0 if remainder == 0 else 4) + 2)
    elif sore_finger == 4:
        print(full_cycles * 8 + (0 if remainder == 0 else 2) + 3)