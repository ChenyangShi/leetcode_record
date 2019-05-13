import sys
import numpy as np

n, k = list(map(int, sys.stdin.readline().split()))

a = [0] + list(map(int, sys.stdin.readline().split()))
dp = np.zeros((n + 1, k + 1))
if a[1] == 1:
    dp[1, 0] = 1
for j in range(1, k + 1):
    dp[1, j] = 1
for i in range(1, n + 1):
    if a[i] == 1:
        dp[i, 0] = 1

ans = 0
for i in range(2, n + 1):
    for j in range(1, k+1):
        if a[i] == 1:
            dp[i, j] = dp[i - 1, j] + 1
        else:
            dp[i, j] = dp[i-1, j-1] + 1
        if dp[i,j] > ans:
            ans = dp[i, j]
print(int(ans))



