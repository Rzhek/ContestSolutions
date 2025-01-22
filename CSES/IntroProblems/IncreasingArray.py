n = int(input())

nums = list(map(int, input().split(" ")))

res = 0; prev = nums[0]-1
for num in nums:
    if (num < prev):
        res += (prev-num)
        num = prev
    prev = num
print(res)