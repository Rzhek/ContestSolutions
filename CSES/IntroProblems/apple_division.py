n = int(input())
nums = list(map(int, input().split()))

def try_all(idx, a, b):
    if idx >= n:
        return abs(b-a) 
    

    res = try_all(idx+1, a+nums[idx], b)
    res = min(res, try_all(idx+1, a, b+nums[idx]))
    return res
print(try_all(0, 0, 0))    