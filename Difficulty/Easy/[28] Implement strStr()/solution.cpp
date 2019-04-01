class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        int tmp = 0;
        for (int i = 0; i < haystack.size(); ++i) 
        {
            tmp = i;
            for (int j = 0; j < needle.size(); ++j) 
            {
                if (haystack[tmp] == needle[j])
                {
                    tmp += 1;
                    if (j == needle.size() - 1)
                        return i;
                }
                else
                {
                    break;
                }
            }
        }
        return -1;
    }
};