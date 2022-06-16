import sys
input = sys.stdin.readline
from collections import deque 

def bfs(myInput, visited) :

    queue = deque([(0, 0)])
    time = 0
 
    while queue:
        for i in range(len(queue)):
            x, y = queue.popleft()
            di = [(0, 1), (0, -1), (1, k)]
            for d in di:
                nx = (x + d[0])%2
                ny = y + d[1]

                if ny >= N :  
                    return 1 

                if myInput[nx][ny] == 1 and visited[nx][ny] == 0 and ny > time:
                    queue.append((nx, ny))
                    visited[nx][ny] = 1

        time += 1
    return 0
 
N, k = map(int, input().split())
myInput = [list(map(int, list(input().rstrip()))) for _ in range(2)]
visited = []
for  i in range(2):
    visited.append([0 for j in range(N)])
print(bfs(myInput, visited))