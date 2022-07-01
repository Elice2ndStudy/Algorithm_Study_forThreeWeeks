# [BOJ] 17144 / 미세먼지 안녕! / 골드4 / 파이썬
# 정답을 보고 해결한 문제
import sys
input = sys.stdin.readline

r, c, t = map(int, input().split())

cleaner = [list(map(int, input().split())) for _ in range(r)]
up = -1
down = -1

# 공기 청정기 위치 찾기
for i in range(r):
    if cleaner[i][0] == -1:
        up = i
        down = i+1
        # print(up , down)
        break

# 미세먼지 확산
def spread():
    # 상 , 좌 , 우 , 하 ( 순서 상관 없음 )
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    # 임시 배열을 만든다.
    temp = [[0] * c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if cleaner[i][j] !=0 and cleaner[i][j] != -1:
                tmp = 0
                for k in range(4):
                    nx = dx[k] + i
                    ny = dy[k] + j
                    # 여기서 약간 헷갈렸는데 임시 배열에 cleaner에서 흩어진 만큼 값을 넣어줌 그리고 tmp에는 그 값을 넣어줘서 cleaner를 만들어 줌
                    if 0 <= nx < r and 0 <= ny < c and cleaner[nx][ny] != -1:
                        temp[nx][ny] += cleaner[i][j] // 5
                        tmp += cleaner[i][j] // 5
                cleaner[i][j] -= tmp

    # 임시 배열과 합쳐서 cleaner를 완성시켜준다.
    for i in range(r):
        for j in range(c):
            cleaner[i][j] += temp[i][j]

# 공기청정기 위쪽 이동 ( 반시계 방향으로 이동 )
def air_up():
    # 우, 상 , 좌 , 하 ( 반시계 )
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]
    direct = 0
    before = 0
    x, y = up, 1
    while True:
        nx = x + dx[direct]
        ny = y + dy[direct]
        if x == up and y == 0:
            break
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            direct += 1
            continue
        cleaner[x][y], before = before, cleaner[x][y]
        x = nx
        y = ny

# 공기청정기 아래쪽 이동 ( 시계 방향 )
def air_down():
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    direct = 0
    before = 0
    x, y = down, 1
    while True:
        nx = x + dx[direct]
        ny = y + dy[direct]
        # 제자리로 돌아오면 끝낸다.
        if x == down and y == 0:
            break
        # 범위를 벗어나면 1증가 시키고 다시 반복한다.
        if nx < 0 or nx >= r or ny < 0 or ny >= c:
            direct += 1
            continue
        # 청소했으면 0으로 초기화하고 before에는 현재값을 넣는다.
        cleaner[x][y], before = before, cleaner[x][y]
        x = nx
        y = ny

for _ in range(t):
    spread()
    air_up()
    air_down()

answer = 0
for i in range(r):
    for j in range(c):
        if cleaner[i][j] > 0:
            answer += cleaner[i][j]

print(answer)