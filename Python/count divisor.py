from math import sqrt
def count_divisors(n):
    res, u = 0, int(sqrt(n))
    for i in range(1, u + 1):
        res += int(n / i - i) * 2 + 1
    return res

print(count_divisors(120445))