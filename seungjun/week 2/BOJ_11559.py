# 뿌요뿌요
# https://www.acmicpc.net/problem/11559

import sys
from collections import deque
input = sys.stdin.readline

dx = [1,-1,0,0]
dy = [0,0,1,-1]
result = 0

graph = []
for _ in range(12):
    graph.append(list(input()))

def bfs (a, b, color):
    visited = [[False for _ in range(6)] for _ in range(12)]
    visited[a][b] = True
    queue = deque()
    queue.append((a,b))
    popped = deque()
    popped.append((a,b))
    count = 1
    didPop = 0
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            #맵을 벗어나면 다음으로 넘어가기
            if nx < 0 or nx >= 12 or ny < 0 or ny >= 6:
                continue
            #색깔이 다르다면 넘어가기
            if graph[nx][ny] != color:
                continue
            #방문한 좌표라면 넘어가기
            if visited[nx][ny]:
                continue
            visited[nx][ny] = True
            queue.append((nx,ny))
            popped.append((nx,ny))
            count += 1
    
    # 4칸이상 연결 되어 있는지 확인 후 터트리기
    if count >= 4:
        didPop = 1
        for x,y in popped:
            graph[x][y] = '.'
    return didPop

# 터진 칸들의 위에 있는 칸들에 대해서 중력 적용
def gravity():
    for y in range(6):
        queue = deque()
        for x in range(11, -1, -1):
            if graph[x][y] != '.':
                queue.append(graph[x][y])
        for x in range(11, -1, -1):
            if queue:
                graph[x][y] = queue.popleft()
            else:
                graph[x][y] = '.'
        # for x in range(12):
        #     print(graph[x])
        # print("")
while True:
    check = 0
    for x in range(12):
        for y in range(6):
            if graph[x][y] != '.':
                check += bfs(x, y, graph[x][y])
    if check == 0:
        print(result)
        break
    else:
        result += 1
    gravity()

# for i in range(12):
#     print(graph[i])