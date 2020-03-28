def get_order(order):
    menus = ['Burger', 'Fries', 'Chicken', 'Pizza', 'Sandwich', 'Onionrings', 'Milkshake', 'Coke']
    res = []
    for menu in menus:
        for i in range(order.count(menu.lower())):
            res.append(menu)
    return " ".join(res)

print(get_order("milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"))