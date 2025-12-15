while True:
    try:
        a = input()
        b = input()
        result = ''

        alphabat = [[0, 0] for _ in range(26)]
        for char in a:
            alphabat[ord(char) - ord('a')][0] += 1
        for char in b:
            alphabat[ord(char) - ord('a')][1] += 1
        for i in range(26):
            if alphabat[i][0] > 0 and alphabat[i][1] > 0:
                result += chr(i + ord('a')) * min(alphabat[i][0], alphabat[i][1])
        print(result)

    except EOFError:
        break

