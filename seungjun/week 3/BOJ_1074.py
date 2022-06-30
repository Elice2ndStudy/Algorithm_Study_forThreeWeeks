# Z
# https://www.acmicpc.net/problem/1074

n, r, c = map(int, input().split())

ans = 0
while (n!=0):
    n -= 1
    # 왼쪽 위
    if r < 2 ** n and c < 2 ** n:
            ans += (2 ** n) * (2 ** n) * 0

    # 오른쪽 위
    elif r < 2 ** n and c >= 2 ** n: 
        ans += (2 ** n) * (2 ** n) * 1
        c -= (2 ** n)
        
    # 왼쪽 아래    
    elif r >= 2 ** n and c < 2 ** n: 
        ans += (2 ** n) * (2 ** n) * 2
        r -= (2 ** n)
        
    # 오른쪽 아래  
    else:
        ans += (2 ** n) * (2 **n) * 3
        r -= (2 ** n)
        c -= (2 ** n)

print(ans)