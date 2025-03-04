from collections import deque


def min_rounds_to_escape():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        u, v = map(int, input().split())
        graph[v].append(u)

    x, y = map(int, input().split())

    def bfs(start):
        dist = [-1] * (n + 1)
        dist[start] = 0
        queue = deque([start])

        while queue:
            u = queue.popleft()
            for v in graph[u]:
                if dist[v] == -1:
                    dist[v] = dist[u] + 1
                    queue.append(v)

        return dist

    dist_from_exit = bfs(n)

    dist_brother = dist_from_exit[x]
    dist_sister = dist_from_exit[y]

    if dist_brother == -1:
        return dist_sister * 2

    if dist_sister == -1:
        return dist_brother * 2 - 1

    return min(dist_brother * 2 - 1, dist_sister * 2)



print(min_rounds_to_escape())
