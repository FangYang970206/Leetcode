class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits:
            return [1]
        carry = 0
        digits[len(digits) - 1] += 1
        for d in range(len(digits) - 1, -1, -1):
            digits[d] += carry
            if digits[d] != 10:
                carry = 0
                break
            else:
                carry = 1
                digits[d] = 0
        if carry == 1:
            digits.append(1)
            digits[0], digits[len(digits) - 1] = digits[len(digits) - 1], digits[0]
        return digits