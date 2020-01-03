class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        if (numbers[right] + numbers[left]) > target:
            while left < right:
                mid = (left + right) // 2
                if (numbers[mid] + numbers[0]) > target:
                    right = mid - 1
                elif (numbers[mid] + numbers[0]) < target:
                    left = mid + 1
                else:
                    return [1, mid + 1]
        while numbers[right] == target:
            right -= 1
        left = 0
        sum = numbers[left] + numbers[right]
        while sum != target:
            if sum > target:
                right -= 1
            else:
                left += 1
            sum = numbers[left] + numbers[right]
        return [left + 1, right + 1]