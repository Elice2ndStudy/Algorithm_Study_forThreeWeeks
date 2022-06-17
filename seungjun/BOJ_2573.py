# 빙산
# https://www.acmicpc.net/problem/2573
import sys
from collections import deque

input = sys.stdin.readline

r, c = map(int, input().split())
iceberg = [list(map(int, input().split())) for _ in range(r)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
year = 0
queue = deque()
check = False

# 녹는 빙산을 바로 반영해버리면 
# 순차적으로 녹아버리는 불상사가 발생하므로, 
# 한 번에 동시에 녹여줘야함

def bfs(a, b):
    queue.append((a,b))
    while queue:
        x, y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < r and 0 <= ny < c:
                if iceberg[nx][ny] != 0 and not visited[nx][ny]:
                    visited[nx][ny] = True
                    queue.append((nx,ny))
                # 상하좌우가 0이면 count++
                elif iceberg[nx][ny] == 0: count[x][y] += 1
    return 1

# 한 바퀴 = 한 개의 빙산이 끝날떄까지
while True:
    year +=1

    visited = [[False] * c] * r
    count = [[0] * c] * r

    result = []
    for i in range(r):
        for j in range(c):
            if iceberg[i][j] != 0 and not visited[i][j]:
                result.append(bfs(i,j))

    # 새로운 빙산 적용
    for i in range(r):
        for j in range(c):
            iceberg[i][j] -= count[i][j]
            if iceberg[i][j] < 0:
                iceberg[i][j] = 0
    
    if len(result) == 0:
        break 
    if len(result) >= 2:
        check = True
        break
    
print(year if check else 0)    

# 참조: https://wookcode.tistory.com/m/155