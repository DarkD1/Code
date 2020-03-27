def cakes(recipe, available):
    res = []
    for k, v in recipe.items():
        i = available.get(k)
        if i:
            res.append(i // v)
        else:
            return 0
    return min(res)

recipe = {"flour": 500, "sugar": 200, "eggs": 1}
available = {"flour": 1200, "sugar": 1200, "eggs": 5, "milk": 200}
print(cakes(recipe, available), 2)