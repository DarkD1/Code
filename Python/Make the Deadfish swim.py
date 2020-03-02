def parse(data):
    arr ,value = [], 0
    for d in data:
        if d == 'i': value = value + 1
        elif d == 'd': value = value - 1
        elif d == 's': value = value * value
        elif d == 'o': arr.append(value)
    return arr        

print(parse('isoisoiso'))
