# [BOJ] 11559 / Puyo Puyo / 골드4 / 파이썬
from collections import deque

puyo = [list(map(str,input())) for _ in range(12)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

res = 0

def bfs(x, y, color):
    queue = deque()
    queue.append([x, y])

    pang = deque()
    pang.append([x, y])

    visited = [[0] * 6 for _ in range(12)]
    visited[x][y] = 1
    cnt = 1
    flag = False

    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 범위안에 있고 방문하지 않았고 color랑 같으면 ..
            if 0 <= nx < 12 and 0<= ny < 6 and visited[nx][ny] == 0 and puyo[nx][ny] == color:
                queue.append([nx,ny])
                pang.append([nx, ny])
                visited[nx][ny] = 1
                cnt += 1

    # pang 2차원 배열을 돌면서 puyo를 초기화 시켜준다.
    if cnt >= 4:
        flag = True
        for i,j in pang:
            puyo[x][y] = "."

    return flag

def down():
    for y in range(6):
        queue = deque()
        for x in range(11, -1, -1):
            if puyo[x][y] != '.':
                queue.append(puyo[x][y])
        for x in range(11, -1, -1):
            if queue:
                puyo[x][y] = queue.popleft()
            else:
                puyo[x][y] = '.'

while True:
    chk = 0
    for i in range(12):
        for j in range(6):
            if puyo[i][j] != '.':
                chk += bfs(i, j, puyo[i][j])

    if chk == 0:
        print(res)
        break
    else:
        res += 1
    down()
