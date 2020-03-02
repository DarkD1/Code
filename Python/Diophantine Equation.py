import math


def sol_equa(n):
    result = []
    for i in range(1, (int)(math.sqrt(n)) + 1):
        if n % i:
            continue
        j = (int) (n / i)
        if (j - i) % 4:
            continue
        result.append([(int)((j + i) / 2), (int)((j - i) / 4)])
    return result


print(sol_equa(12))
