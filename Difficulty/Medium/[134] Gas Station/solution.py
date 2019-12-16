class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        size = len(gas)
        for id in range(size):
            gas_num = 0
            for i in range(id, size):
                gas_num += gas[i]
                gas_num -= cost[i]
                if gas_num < 0:
                    break
            if gas_num >= 0:
                for j in range(id):
                    gas_num += gas[j]
                    gas_num -= cost[j]
                    if gas_num < 0:
                        break
                if gas_num >= 0: return id
        return -1