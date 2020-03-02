def josephus(items,k):
    n, lastp, result = len(items), len(items) - 1, []
    for i in range(0, n):
        result.append(items.pop((lastp + k) % (n - i)))
        lastp = (lastp + k) % (n - i) - 1
    return result

print(josephus([1,2,3,4,5,6,7,8,9,10],1))
