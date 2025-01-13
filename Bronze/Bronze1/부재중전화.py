N, L, D = map(int, input().split())

time = L # 현 시간
ring = D # 울리는 시간

for i in range(1,N+1):
  # ring < time <= ring + L
  if time <= ring + L and ring < time:
    while ring < time:
      ring += D
    time += L + 5
  # ring - 5 < time <= ring
  elif ring >= time and ring - 5 < time:
    break
  else:
    time += L + 5
print(ring)