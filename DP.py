import numpy as np
arr =[3, 34, 4, 12, 5, 2]
arr2 = [1, 2, 4, 1, 7, 8, 3]

#不相邻数字的最大和
def rec_opt(arr, i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0], arr[1])
    else:
        A = rec_opt(arr, i-2) + arr[i] # 选
        B = rec_opt(arr, i-1) # 不选
        return max(A, B)

def dp_opt(arr):
    opt = np.zeros(len(arr))
    opt[0] = arr[0]
    opt[1] = max(arr[0], arr[1])
    for i in range(2, len(arr)):
        A = opt[i-2] + arr[i]
        B = opt[i-1]
        opt[i] = max(A, B)

    return opt[ len(arr)-1 ]


print(dp_opt(arr2))
print(rec_opt(arr2, len(arr2)-1))



# 是否能选出数字使得其之和等于s       
def rec_subset(arr, i, s):
    if s == 0:
        return True
    elif i == 0:
        return arr[0] == s
    elif arr[i] > s:
        return rec_subset(arr, i-1, s)
    else:
        A = rec_subset(arr, i-1, s-arr[i]) #select
        B = rec_subset(arr, i-1, s) #not select
        return A or B

def dp_subset(arr, s):
    subset = np.zeros((len(arr), s+1), dtype=bool)
    subset[:,0] = True
    subset[0,:] = False
    subset[0, arr[0]] = True
    for i in range(1, len(arr)):
        for j in range(1, s+1):
            if arr[i] > s:
                subset[i, s] = subset[i-1, s]
            else:
                A = subset[i-1, s-arr[i]] #select
                B = subset[i-1, s] #not select
                subset[i, s] = A or B

    r, c = subset.shape
    return subset[r-1, c-1]

print(rec_subset(arr, len(arr)-1, 9))
print(dp_subset(arr, 13))
