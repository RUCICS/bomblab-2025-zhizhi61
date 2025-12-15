
grid = [
    [0, 0, 1, 0, 0, 1, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 1, 0, 0],
    [1, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0, 1, 0],
    [1, 0, 0, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 0, 0, 0, 0] 
]

moves = [
    (-2, 1), (-1, 2), (1, 2), (2, 1),
    (2, -1), (1, -2), (-1, -2), (-2, -1)
]

checks = [
    (-1, 0), (0, 1), (0, 1), (1, 0),
    (1, 0), (0, -1), (0, -1), (-1, 0)
]

queue = [(0, 0, [])]
# visited = set([(0, 0)]) # Don't use visited, allow re-entry if needed, but BFS finds shortest.

while queue:
    x, y, path = queue.pop(0)
    if x == 4 and y == 7:
        print("Found path:", path)
        break
    
    if len(path) >= 19:
        continue

    for k in range(8):
        dx, dy = moves[k]
        cx, cy = checks[k]
        
        nx, ny = x + dx, y + dy
        chk_x, chk_y = x + cx, y + cy
        
        # Check bounds and walls for intermediate
        if 0 <= chk_x < 8 and 0 <= chk_y < 8:
            if grid[chk_x][chk_y] == 1:
                continue
        else:
            continue 
            
        # Check bounds and walls for destination
        if 0 <= nx < 8 and 0 <= ny < 8:
            if grid[nx][ny] == 1:
                continue
            
            new_path = path + [k]
            queue.append((nx, ny, new_path))
