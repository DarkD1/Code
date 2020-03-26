def update(tree, i, n):
    j = i
    while j <= n:
        tree[j] += 1
        j += (j & -j)

def query(tree, i):
    sum, j = 0, i
    while j > 0:
        sum += tree[j]
        j -= (j & -j)
    return sum

def binary_simulation(s, q):
    l, res = len(s), []
    tree = [0] * (l + 1)
    for i in range(len(q)):
        if q[i][0] == 'I':
            update(tree, q[i][1], l)
            update(tree, q[i][2] + 1, l)
        else:
            ans = query(tree, q[i][1]) % 2
            val = ''
            if ans:
                val = '1' if s[q[i][1] - 1] == '0' else '0'
            else:
                val = s[q[i][1] - 1]
            res.append(val)
    return res


print(binary_simulation('0000000000', [['I', 1, 10], ['Q', 2]]))