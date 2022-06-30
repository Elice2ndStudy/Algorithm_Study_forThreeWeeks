import sys
input = sys.stdin.readline

def binary():
    left = 1
    right = max(myInput)
    while left <= right:
        mid = (left + right) // 2
        tree_sum = 0
        for i in range(N):
            if myInput[i] >= mid:
                tree_sum += myInput[i] - mid
        if tree_sum >= M:
            left = mid + 1
        else:
            right = mid - 1
    return right

N, M = map(int, input().split())
myInput = list(map(int, input().split()))
print(binary())