# [BOJ] 14503 / 로봇 청소기 / 골드5 / 파이썬

n , m = map(int,input().split())
x,y,d = map(int,input().split())
robot = [list(map(int,input().split())) for _ in range(n)]

visited = [[0] * m for _ in range(n)]
print(visited)
# 북 , 서 , 남 , 동
dx=[-1, 0, 1, 0]
dy=[0, 1, 0, -1]

# 방향 전환
def left():
    global d
    d -= 1
    if d == -1:
        d = 3


visited[x-1][y-1] = 1
repeat = 0
cnt = 1

while True:
    # 방향 전환 후 이동!
    left()
    nx = x + dx[d]
    ny = y + dy[d]
    # 만약 그곳이 방문하지 않았거나 빈 공간인 경우
    if visited[nx][ny] == 0 and robot[nx][ny] == 0:
        visited[nx][ny] = 1
        x, y = nx, ny
        cnt += 1
        repeat = 0
        continue
    else:
        repeat += 1
    # 4번 반복했는데 뒤에 벽쪽이면 멈추고 아니면 후진한다.
    if repeat == 4:
        nx = x - dx[d]
        ny = y - dy[d]
        if robot[nx][ny] == 0:
            x,y = nx,ny
        else:
            break
        repeat = 0
print(visited)
print(robot)
print(cnt)




