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

1. 采用双map。

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

2. 采用求取哈希值，判断哈希值是否相等。

```c++
class Solution2 {
// The general idea:
// Construct a hash function f for L, f: vector<string> -> int, 
// Then use the return value of f to check whether a substring is a concatenation 
// of all words in L.
// f has two levels, the first level is a hash function f1 for every single word in L.
// f1 : string -> double
// So with f1, L is converted into a vector of float numbers
// Then another hash function f2 is defined to convert a vector of doubles into a single int.
// Finally f(L) := f2(f1(L))
// To obtain lower complexity, we require f1 and f2 can be computed through moving window.
// The following corner case also needs to be considered:
// f2(f1(["ab", "cd"])) != f2(f1(["ac", "bd"]))
// There are many possible options for f2 and f1. 
// The following code only shows one possibility (probably not the best), 
// f2 is the function "hash" in the class,
// f1([a1, a2, ... , an]) := int( decimal_part(log(a1) + log(a2) + ... + log(an)) * 1000000000 )
public:
    // The complexity of this function is O(nW).
    //基于字符对每个单词生成哈希值
    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        // 构建均匀分布，0到1
        uniform_real_distribution<double> unif(0., 1.);
        //随机种子
        default_random_engine seed;
        //128对应的是ASCII的个数
        double code[128];
        //对每个ASCII从0到1之间随机均匀取值
        for (auto &d : code) d = unif(seed);
        // 随机乘子
        double f = unif(seed) / 5. + 0.8;
        // 存储L最终的哈希值
        double value = 0;

        // The complexity of the following for loop is O(L.size( ) * nW).
        // 求取L的哈希值log(a1) + log(a2) + ... + log(an)，a1,...an对应L中的单词
        for (auto &str : L) value += log(hash(f, code, str));

        int unit = 1e9;
        // 得到key，用于判断最后substr是否与之相等
        int key = (value-floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        // 代表hash函数中result的次数，见values求值
        double fn = pow(f, nW-1.);
        //存储最后结果
        vector<int> result;
        if (nS < nW) return result;
        //存储s中每个单词长度字符串的哈希值
        vector<double> values(nS-nW+1);
        //取s第一个单词
        string word(S.begin(), S.begin()+nW);
        //得到s第一个哈希值
        values[0] = hash(f, code, word);

        // Use a moving window to hash every word with length nW in S to a float number, 
        // which is stored in vector values[]
        // The complexity of this step is O(nS).
        //这一步使用滑动窗口求值，例如s=‘abcde', 求得’abcd‘的哈希值，根据’abcd‘的哈希值，求’bcde‘的哈希值
        //只要减去’a'的哈希值（在hash函数中这里'a'的code值，是经过了累积的，所以这里减去'a'的code以及次方fn
        //然后加上‘e’的code值即可, 与hash保持一致
        for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];

        // This for loop will run nW times, each iteration has a complexity O(nS/nW)
        // So the overall complexity is O(nW * (nS / nW)) = O(nS)
        //外循环nw次，因为nw处与0处就间隔一个word，滑窗word长度就重复了，所以只需循环nw即可
        for (int i=0; i<nW; ++i) {
            int j0=i, j1=i, k=0;
            double sum = 0.;

            // Use a moving window to hash every L.size() continuous words with length nW in S.
            // This while loop will terminate within nS/nW iterations since the increasement of j1 is nW,
            // So the complexity of this while loop is O(nS / nW).
            //累加哈希值，与key进行比较，相等则push到result中，然后减去第0个值，继续循环加上下一个值，
            //直到最后j1小于最小长度。
            while(j1<=nS-nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k==nL) {
                    int key1 = (sum-floor(sum)) * unit;
                    if (key1==key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};
```