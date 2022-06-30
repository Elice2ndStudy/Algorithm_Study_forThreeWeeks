import sys 
input = sys.stdin.readline

def QuadTree(x, y, N):
    
    for i in range(x, x + N):
        for j in range(y, y + N):
            if myInput[i][j] != myInput[x][y]:
                print("(", end="")
                QuadTree(x, y, N//2) #왼쪽 위
                QuadTree(x, y + N//2, N//2) #오른쪽 위
                QuadTree(x + N//2, y, N//2) #왼쪽 아래
                QuadTree(x + N//2, y + N//2, N//2) #오른쪽 아래
                print(")", end="")
                return 

    print(myInput[x][y], end="")

N = int(input())
myInput = [list(map(int, input().strip())) for _ in range(N)]
QuadTree(0, 0, N)
