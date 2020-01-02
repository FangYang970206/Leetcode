class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        vs1_list = version1.split('.')
        vs2_list = version2.split('.')
        vs1_list = self.removePreZeros(vs1_list)
        vs2_list = self.removePreZeros(vs2_list)
        vs1_list = self.removeLstZeros(vs1_list)
        vs2_list = self.removeLstZeros(vs2_list)
        for i in range(min(len(vs1_list), len(vs2_list))):
            if int(vs1_list[i]) > int(vs2_list[i]):
                return 1
            elif int(vs1_list[i]) < int(vs2_list[i]):
                return -1
        if len(vs1_list) == len(vs2_list):
            return 0
        elif len(vs1_list) > len(vs2_list):
            return 1
        else:
            return -1
    
    def removePreZeros(self, version_list):
        new_version_list = []
        for s in version_list:
            i = 0
            for elem in s:
                if elem == '0':
                    i += 1
                else:
                    break
            if s[i:]:
                new_version_list.append(s[i:])
            else:
                new_version_list.append('0')
        return new_version_list

    def removeLstZeros(self, version_list):
        lst_index = len(version_list)
        for i in range(len(version_list) - 1, -1, -1):
            if version_list[i] == '0':
                lst_index = i
            else:
                break
        return version_list[:lst_index]

if __name__ == "__main__":
    version1 = "1.2"
    version2 = "1.10"
    solu = Solution()
    print(solu.compareVersion(version1, version2))