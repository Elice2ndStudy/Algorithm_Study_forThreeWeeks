import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
    
def dfs(x, y):
    if x == M-1 and y == N-1:
        return 1
    if visited[x][y] == -1:
        visited[x][y] = 0 
        di = [(1,0), (-1, 0), (0, 1), (0, -1)]
        for d in di:
            nx = x + d[0]
            ny = y + d[1]
            if nx < 0 or ny < 0 or nx > M-1 or ny > N-1: continue
            if myInput[nx][ny] < myInput[x][y] :
                visited[x][y] += dfs(nx, ny)
    return visited[x][y]

M, N = map(int, input().split())
myInput = [list(map(int, input().split())) for _ in range(M)]
visited = []
for  i in range(M):
    visited.append([-1 for j in range(N)])
print(dfs(0, 0))
