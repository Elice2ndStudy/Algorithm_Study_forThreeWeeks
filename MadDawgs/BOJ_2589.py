import sys
input = sys.stdin.readline
from collections import deque

def bfs(i, j, k) :
    visited = [[0]*m for _ in range(n)]
    visited[i][j] = 1
    queue = deque([(i, j, k)])
    while queue:
        for _ in range(len(queue)):
            x, y, depth = queue.popleft()
            di = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            for d in di:
                nx = x + d[0]
                ny = y + d[1]

                if nx >= n or ny >= m or nx < 0 or ny < 0:  
                    continue 

                if myInput[nx][ny] == myInput[x][y] and visited[nx][ny] == 0:
                    queue.append((nx, ny, depth+1))
                    visited[nx][ny] = 1

    return depth

def findMaxTime():
    time = 0
    
    for i in range(n):
        for j in range(m):
            if myInput[i][j] == "L": 
                time = max(time, bfs(i, j, 0))
    return time
 
n, m = map(int, input().split())
myInput = [list(input().rstrip()) for _ in range(n)]
visited = [[0]*m for _ in range(n)]

print(findMaxTime())