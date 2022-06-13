import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def dfs(x, y):
    visited[x][y] = 1
    di = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for d in di:
        nx = x + d[0]
        ny = y + d[1]
        if nx >= N or ny >= N or nx < 0 or ny < 0: continue
        if myInput[nx][ny] == myInput[x][y] and visited[nx][ny] == 0:
                dfs(nx, ny)

def countSection() : 
    count_1 = 0
    count_2 = 0
    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                count_1 += 1
                dfs(i, j)

    for i in range (N):
        for j in range(N):
            visited[i][j] = 0
    for i in range (N):
        for j in range(N):
            if myInput[i][j] == "G":
                myInput[i][j] = "R"

    for i in range(N):
        for j in range(N):
            if visited[i][j] == 0:
                count_2 += 1
                dfs(i, j)

    return [count_1, count_2]

N = int(input())
myInput = [list(input().rstrip()) for _ in range(N)]
visited = []
for  i in range(N):
    visited.append([0 for j in range(N)])

print(" ".join(map(str, countSection())))
