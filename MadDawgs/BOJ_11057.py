import sys
input = sys.stdin.readline
def dp(N) :
    count = [1] * 10
    for i in range(1, N):
        for j in range(1, 10):
            count[j] += count[j - 1]
    return sum(count)%10007
    
N = int(input().rstrip())
print(dp(N))