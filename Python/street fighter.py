def street_fighter_selection(fighters, initial_position, moves):
    res, current_pos, row, col = [], initial_position, len(fighters), len(fighters[0])
    for move in moves:
        if move == 'right':
            current_pos = (current_pos[0], (current_pos[1] + 1) % col) 
        elif move == 'left':
            current_pos = (current_pos[0], (current_pos[1] - 1) % col)
        elif move == 'down':
            current_pos = ((current_pos[0] if current_pos[0] == row - 1 else current_pos[0] + 1) % row, current_pos[1])
        elif move == 'up':
            current_pos = (current_pos[0] if current_pos[0] == 0 else (current_pos[0] - 1) % row, current_pos[1])
        
        res.append(fighters[current_pos[0]][current_pos[1]]) 
    
    return res


fighters = [['Ryu', 'E.Honda', 'Blanka', 'Guile', 'Balrog', 'Vega'], ['Ken', 'Chun Li', 'Zangief', 'Dhalsim', 'Sagat', 'M.Bison']]
initial_position = (0,0)
moves = ['left', 'left', 'left', 'left', 'left', 'left', 'left', 'left']

print(street_fighter_selection(fighters, initial_position, moves))