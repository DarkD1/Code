def multiplication_table(row,col):
    table = [ [0]*row for i in range(col)]
    for i in range(row):
        for j in range(col):
            table[i][j] = (i+1) * (j+1)
    return table

def multiplication_table(row, col):
    return [[(i+1)*(j+1) for j in range(col)] for i in range(row)]


print(multiplication_table(3,3))