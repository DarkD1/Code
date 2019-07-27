from math import sqrt


def fantabulous_birthday(n):
    p = round(sqrt(n))
    col = p * p - n + 1 if p * p >= n else n - p * p
    row = p if p * p >= n else p + 1
    return [col, row] if p % 2 else [row, col]
