class Solution:
    def candy(self, ratings: List[int]) -> int:
        size, candies = len(ratings), [1] * len(ratings)
        for i in range(1, size):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        sum = candies[size - 1]
        for j in range(size-2, -1, -1):
            if candies[j] > candies[j + 1]:
                sum += max(candies[j], candies[j + 1] + 1)
        return sum