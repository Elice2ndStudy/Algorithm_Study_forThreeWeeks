# 나무 자르기
# https://www.acmicpc.net/problem/2805  

# 벌목 높이를 바꿔가며 필요 나무 길이가 충족되는지 확인해본다.

n, m = map(int, input().split())
trees = list(map(int, input().split()))

start = 0
end = max(trees)


while start <= end:    
    mid = (start + end) // 2
    cut = 0
    # 벌목된 나무 합하기
    for tree in trees:
        if tree >= mid:
            cut += tree - mid
    
    # 벌목된 나무가 목표치보다 높거나 낮음에 따라 mid 조절
    if cut >= m:
        start = mid + 1
    else:
        end = mid - 1

print(end)
