N, K = map(int, input().split())

# 1 ~ N까지 숫자 리스트 생성
numbers = list(range(1, N + 1))
result = []
index = 0

# 리스트가 빌 때까지 반복
while numbers:
    # K-1번째 숫자를 제거하기 위해 index를 K-1만큼 이동(원순열)
    index = (index + K - 1) % len(numbers)
    # 제거된 숫자를 결과 리스트에 추가
    result.append(str(numbers.pop(index)))

# 결과 출력
print("<" + ", ".join(result) + ">")