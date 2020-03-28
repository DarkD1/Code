def letter_count(s):
    res = {}
    for c in s:
        res[c] = res.get(c, 0) + 1
    return res 

print(letter_count('arithmetic'))