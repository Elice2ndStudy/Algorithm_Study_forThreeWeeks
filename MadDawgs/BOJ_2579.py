import sys
input = sys.stdin.readline

def stair (data):
    if (N == 1): return data[0]
    if (N == 2): return data[0] + data[1]
    if (N == 3): return max(data[0] + data[2], data[1] + data[2]) 
    score = [0] * N
    score[0] = data[0] 
    score[1] = data[0] + data[1]
    score[2] = max(data[0] + data[2], data[1] + data[2])
    for i in range(3, N):
        score[i] = max(data[i] + score[i-2], data[i] + data[i-1] + score[i-3])
    return score[N-1]


N = int(input().strip())
myInput = [int(input().strip()) for _ in range(N)]
print(stair(myInput))