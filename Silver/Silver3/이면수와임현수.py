n = int(input())
num = [int(i) for i in str(n)]

def factorization(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


imunsu = False
if sum(num) % 2 == 1:
    if n == 4 or n >= 6:
        imunsu = True

imhyunsu = False
if n == 2 or n == 4:
    imhyunsu = True
else:
    factors = set(factorization(n))
    if len(factors) % 2 == 0 and len(factors) != 0:
        imhyunsu = True


if imunsu and imhyunsu:
    print(4)
elif imunsu:
    print(1)
elif imhyunsu:
    print(2)
else:
    print(3)