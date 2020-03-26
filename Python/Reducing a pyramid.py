def reduce_pyramid(base):
    n , res, inc = len(base) - 1, 0, 1
    for i in range(0, n + 1):
        res = res + (inc * base[i])
        inc = inc * ((n - i) / (i + 1))
    return (int)(res)

print(reduce_pyramid([3, 5]))
