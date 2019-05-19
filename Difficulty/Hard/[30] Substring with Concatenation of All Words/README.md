# 问题描述
给你一个字符串s，和一列单词words，它们都是相同长度的。在s中找到所有子字符串的起始索引，该索引是单词中每个单词的一次连接，并且不包含任何中间字符。
# 例子
```bash
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
```

# 方法
采用双map。
```c++
vector<int> findSubstring(string s, vector<string>& words) {
    // counts 用来对words中的word进行计数
    unordered_map<string, int> counts;
    // 存储最后的结果
    vector<int> res;
    // 如果输入为空，返回空向量
    if (s.size() == 0 || words.size() == 0)
        return res;
    // 遍历words，使用counts进行计数
    for (auto& str : words) counts[str] += 1;
    // 定义字符串长度，单词向量长度，单词长度
    int n = s.size(), num = words.size(), word_len = words[0].size();
    // 外循环遍历字符串中的每个字符
    for (int i = 0; i < n - num * word_len + 1; i++){
        // 建立哈希表，目的是对看过的单词进行计数
        unordered_map<string, int> seen;
        int j = 0;
        while (j < num){
            // 取字符串分量，长度为word的长度
            string temp = s.substr(i + j * word_len, word_len);
            // 如果再counts发现这个字符串，则再seen中进行计数
            if (counts.find(temp) != counts.end()){
                seen[temp] += 1; // 计数
                // 如果计数超过了counts中的数量则退出
                if (seen[temp] > counts[temp])
                    break;
            }else{
                break;
            }
            j++; //自增，进入下一个word
        }
        // 如果j等于num，说明seen中每个word的数量与counts中一样，i满足条件
        if (j == num) res.push_back(i);
    }
    return res;
}
```