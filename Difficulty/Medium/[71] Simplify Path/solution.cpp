/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string simp_path;
        bool continuous_dot_flag = false;
        vector<char> path_chars;
        path_chars.push_back('/');
        for(int i = 1; i < path.size(); ++i) {
            if(path[i] == '/'){
                continuous_dot_flag = false;
                if(path_chars.back() != '/')
                    path_chars.push_back(path[i]);
            }
            else if(path[i] == '.'){
                if (continuous_dot_flag)
                    path_chars.push_back('.');
                else if(i + 1 < path.size()){
                        if(path[i + 1] == '.'){
                            if(i + 2 < path.size() && path[i + 2] != '/'){
                                if(path[i + 2] == '.')
                                    continuous_dot_flag = true;
                                path_chars.push_back(path[i]);
                            }
                            else if(path_chars.size() != 1){
                                path_chars.pop_back();
                                while(path_chars.back() != '/')
                                    path_chars.pop_back();
                                ++i;
                            }
                        }else if(path[i + 1] != '/')
                            path_chars.push_back(path[i]);
                }
            }else{
                continuous_dot_flag = false;
                path_chars.push_back(path[i]);
            }
        }
        if(path_chars.back() == '/' && path_chars.size() != 1)
            path_chars.pop_back();
        for(auto& c : path_chars){
            simp_path += c;
        }
        return simp_path;
    }
};

