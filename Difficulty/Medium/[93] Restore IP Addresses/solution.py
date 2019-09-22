class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) >= 11:
            min_len = 2
        else:
            min_len = 1
        res = []
        self.restoreIpAddressesHelper(res, s, "", 0 , 0, min_len)
        return res
    
    def restoreIpAddressesHelper(self, res, s, tmp, count, begin, min_len):
        if count == 4:
            if len(tmp) == len(s) + 3:
                res.append(tmp[:])
            return
        
        for i in range(min_len, 3+1):
            if begin > len(s) - 1:
                return;
            if s[begin] == '0' and i > 1:
                return
            if begin + i > len(s):
                return
            if (int(s[begin : begin+i]) <= 255):
                if not tmp:
                    self.restoreIpAddressesHelper(res, s, tmp + s[begin : begin+i], count + 1, begin + i, min_len)
                else:
                    self.restoreIpAddressesHelper(res, s, tmp + '.' + s[begin : begin+i], count + 1, begin + i, min_len)
        