class Solution1:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        if len(nums) == 4:
            return [nums] if sum(nums) == target else []
        nums.sort()
        nums_len = len(nums)
        res = []
        for i in range(nums_len - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i+1, nums_len - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                l, r = j + 1, nums_len - 1
                while l < r:
                    total = nums[i] + nums[j] + nums[l] + nums[r]
                    if total > target:
                        r -= 1
                    elif total < target:
                        l += 1
                    else:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        l += 1
                        r -= 1
        return res

# inspired by https://leetcode.com/problems/4sum/discuss/8545/Python-140ms-beats-100-and-works-for-N-sum-(Ngreater2)
class Solution2:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        if len(nums) == 4:
            return [nums] if sum(nums) == target else []
        nums.sort()
        nums_len = len(nums)
        res = []
        for i in range(nums_len - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i+1, nums_len - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                l, r = j + 1, nums_len - 1
                while l < r:
                    if (target-(nums[i]+nums[j])) > 2*nums[r] or (target-(nums[i]+nums[j])) < 2*nums[l]:
                        break
                    total = nums[i] + nums[j] + nums[l] + nums[r]
                    if total > target:
                        r -= 1
                    elif total < target:
                        l += 1
                    else:
                        res.append([nums[i], nums[j], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        l += 1
                        r -= 1
        return res

# come from Accepted Solutions Runtime Distribution
class Solution3:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n < 4:
            return []
        res = []
        nums = sorted(nums)
        hi = nums[-1]
        num2id = {x:i for i,x in enumerate(nums)}
        for i in range(n-3):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            a = nums[i]
            if a*4 >target:
                return res
            if  a+3*hi<target:
                continue
            for j in range(i+1,n-2):
                if j > i+1 and nums[j]==nums[j-1]:
                    continue
                b = nums[j]
                if a+b*3 >target:
                    break
                if a+b+2*hi<target:
                    continue
                for k in range(j+1,n-1):
                    if k > j+1 and nums[k]==nums[k-1]:
                        continue
                    c = nums[k]
                    if a+b+c*2>target:
                        break
                    if a+b+c+hi<target:
                        continue
                    d = target-a-b-c
                    if d in num2id:
                        l = num2id[d]
                        if l <= k:
                            break
                        else:
                            res.append([a,b,c,d])
        return res