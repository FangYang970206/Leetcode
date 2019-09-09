class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return len(nums)
        count, dup_ind, size, flag = 1, 0, len(nums), False
        for move_ind in range(len(nums) - 1):
            if nums[move_ind] == nums[move_ind + 1]:
                count += 1
                if flag and count <= 3 and move_ind > dup_ind:
                    nums[dup_ind] = nums[move_ind]
                    dup_ind += 1
            else:
                if count > 2:
                    if not flag:
                        dup_ind = move_ind - count + 3
                        flag = True
                else:
                    if flag and move_ind > dup_ind:
                        nums[dup_ind] = nums[move_ind]
                        dup_ind += 1
                count = 1
        if count == size:
            dup_ind = 2
        elif count > 2:
            dup_ind = dup_ind if flag else size - count + 2
        else:
            if flag:
                nums[dup_ind] = nums[size - 1]
                dup_ind += 1
            else:
                dup_ind = size
        for _ in range(size - dup_ind):
            nums.pop()
        return dup_ind
                        