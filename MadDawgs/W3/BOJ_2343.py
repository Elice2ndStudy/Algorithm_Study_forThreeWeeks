import sys
input = sys.stdin.readline

def binary():
    start = max(myInput)
    end = sum(myInput)
    while start <= end:
        mid = (start + end) // 2 #블루레이의 크기
        count = 1 #블루레이의 갯수
        _sum = 0
        for i in range(N):
            _sum += myInput[i] 
            if _sum > mid:
                count += 1
                _sum = myInput[i]

        if count <= M:
            answer = mid
            end = mid - 1
            
        else:
            start = mid + 1

    return answer

N, M = map(int, input().split())
myInput = list(map(int, input().split()))
print(binary())