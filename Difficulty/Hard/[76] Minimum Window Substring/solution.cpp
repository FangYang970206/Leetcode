/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c : t) ++map[c];
        int begin = 0, end = 0, min_len = INT_MAX, min_begin = 0, counter = t.size(), s_size = s.size();
        while (end < s_size) {
            if (map[s[end]] > 0)
                --counter;
            --map[s[end]];
            ++end;
            while (counter == 0){
                if (end - begin < min_len){
                    min_begin = begin;
                    min_len = end - begin;
                }
                map[s[begin]]++;
                if (map[s[begin]] > 0)
                    counter++;
                ++begin;
            }
        } 
        if (min_len != INT_MAX)
            return s.substr(min_begin, min_len);
        return "";
    }
};
// bad implementation, Time Limit Exceeded 
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_hash_table;
        vector<int> positions;
        for(auto& c : t)
            t_hash_table[c]++;
        for(int i = 0; i < s.size(); ++i){
            if (t_hash_table.find(s[i]) != t_hash_table.end())
                positions.push_back(i);
        }
        if(positions.empty()) return "";
        int t_len = t.size();
        for(int length = t_len; length <= s.size(); length++){
            if (positions.size() < t_len)
                return "";
            for(int i = positions[0]; i <= positions[positions.size() - t_len]; ++i){
                if(i + length > s.size())
                    break;
                else{
                    if (isValid(s.substr(i, length), t_hash_table))
                        return s.substr(i, length);
                }
            }
        }
        return "";
    }

    bool isValid(const string& s, const unordered_map<char, int>& ht){
        auto ht_tmp = ht;
        for (auto& c : s){
            if (ht_tmp.find(c) != ht_tmp.end())
                    --ht_tmp[c];
        }
        for (auto& t : ht_tmp){
            if (t.second > 0)
                return false;
        }
        return true;
    }
};

