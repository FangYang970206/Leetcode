/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 * 
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string res_elem;
        if (words.size() == 1){
            res_elem += words[0];
            res_elem += string(maxWidth - words[0].size(), ' ');
            res.push_back(res_elem);
            return res;
        }
        int word_begin_index = 0;
        int res_elem_nums = 0;
        int res_elem_least_len = 0;
        for (auto& w : words){
            res_elem_least_len += w.size();
            if (res_elem_least_len + res_elem_nums > maxWidth){
                if (res_elem_nums == 1){
                    res_elem += words[word_begin_index];
                    res_elem += string(maxWidth - words[word_begin_index].size(), ' ');
                }else{
                    int spaces = maxWidth - (res_elem_least_len - w.size());
                    int sub_space = spaces / (res_elem_nums - 1);
                    int other_space = spaces % (res_elem_nums - 1);
                    for (int i = word_begin_index, j = 0; i < word_begin_index + res_elem_nums - 1; ++i, ++j){
                        res_elem += words[i];
                        res_elem += string(j < other_space ? sub_space + 1 : sub_space, ' ');
                    }
                    res_elem += words[word_begin_index + res_elem_nums - 1];
                }
                res.push_back(res_elem);
                res_elem = "";
                res_elem_least_len = w.size();
                word_begin_index += res_elem_nums;
                res_elem_nums = 1;
                if (word_begin_index == words.size() - 1){
                    res_elem += words[word_begin_index];
                    res_elem += string(maxWidth - words[word_begin_index].size(), ' ');
                    res.push_back(res_elem);
                    return res;
                }
            }else if (res_elem_least_len + res_elem_nums == maxWidth){
                for (int i = word_begin_index; i < word_begin_index + res_elem_nums; i++){
                    res_elem += words[i];
                    res_elem += " ";
                }
                res_elem += words[word_begin_index + res_elem_nums];
                res.push_back(res_elem);
                res_elem = "";
                res_elem_least_len = 0;
                word_begin_index += res_elem_nums + 1;
                res_elem_nums = 0;
                if (word_begin_index == words.size() - 1){
                    res_elem += words[word_begin_index];
                    res_elem += string(maxWidth - words[word_begin_index].size(), ' ');
                    res.push_back(res_elem);
                    return res;
                }
            }else
                res_elem_nums++;
        }
        if (res_elem_nums > 1){
            res_elem = "";
            for (int i = word_begin_index; i < word_begin_index + res_elem_nums; i++){
                res_elem += words[i];
                res_elem += " ";
            }
            res_elem += string(maxWidth - res_elem.size(), ' ');
            res.push_back(res_elem);
        }
        return res;
    }
};

