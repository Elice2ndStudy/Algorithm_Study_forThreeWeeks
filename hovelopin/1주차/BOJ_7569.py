from collections import deque

M,N,H = map(int,input().split())

farm = [[list(map(int,input().split())) for _ in range(N)] for _ in range(H)]

dx = [-1,1,0,0,0,0]
dy = [0,0,-1,1,0,0]
dz = [0,0,0,0,-1,1]

cnt = 0

def bfs():
    while queue:
        z,x,y = queue.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]
            # 다음날 탐색할때 0인부분을 1로 만들어준다!
            if 0<= nx < N and 0 <= ny < M and 0<= nz < H and farm[nz][nx][ny] == 0:
                farm[nz][nx][ny] = farm[z][x][y] + 1
                queue.append([nz,nx,ny])

# 일단 기본적으로 1일때 queue에 넣어둔다. 왜냐하면 다음날부터 0인곳을 1로 만들어줄거기 때문에!
queue = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if( farm[i][j][k] == 1):
                queue.append([i,j,k])

bfs()
print(farm)

# 한층씩 접근한다.  => 즉 , H 접근
for i in farm:
		# 그 층에서 한줄씩 접근한다. => 즉 , 한 행
    for j in i:
				# 거기서 원소 하나씩 접근 => 행과 열
        for k in j:
            if k == 0:
                print(-1)
                exit()
        cnt= max(cnt , max(j))

print(cnt-1)