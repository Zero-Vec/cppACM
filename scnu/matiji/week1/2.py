def map_update():
    n, m = map(int, input().split())

    adj_matrix = [[0] * (n + 1) for _ in range(n + 1)]

    for _ in range(m):
        u, v = map(int, input().split())
        adj_matrix[u][v] = adj_matrix[v][u] = 1

    q = int(input())

    seen_maps = set()

    seen_maps.add(tuple(tuple(row) for row in adj_matrix))

    for _ in range(q):
        update = input().split()
        if update[0] == "add":
            u, v = int(update[1]), int(update[2])
            adj_matrix[u][v] = adj_matrix[v][u] = 1
        elif update[0] == "del":
            u, v = int(update[1]), int(update[2])
            adj_matrix[u][v] = adj_matrix[v][u] = 0
        elif update[0] == "pop":
            u = int(update[1])
            for v in range(1, n + 1):
                adj_matrix[u][v] = adj_matrix[v][u] = 0

        current_map = tuple(tuple(row) for row in adj_matrix)

        if current_map in seen_maps:
            print("old")
        else:
            print("new")
            seen_maps.add(current_map)


map_update()
