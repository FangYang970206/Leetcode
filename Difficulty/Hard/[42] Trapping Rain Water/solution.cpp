// so powerful
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};



// my method is not finished, so bad.

class Solution {
public:
    int trap(vector<int>& height) {
        int l = -1, r = -1;
        int pre_l = -1, pre_r = -1;
        int max_v = 0;
        int res = 0;
        unordered_map<int, vector<int>> dict; 
        for (int i = 0; i < height.size(); ++i){
            if (dict.find(height[i]) != dict.end()){
                if (dict[height[i]].size() == 2)
                    dict[height[i]][1] = i;
                else
                    dict[height[i]].push_back(i);
            }
            else
                dict[height[i]].push_back(i);
            if (height[i] > max_v)
                max_v = height[i];
        }
        vector<int> temp;
        for (int i = 0; i < height.size(); ++i){
            if (height[i] == max_v)
                temp.push_back(i);
        }
        if (temp.size() >= 2){
            l = temp[0];
            r = *(--temp.end());
            res += (r - l + 1) * max_v;
            max_v--;
        }
        while(max_v && (l != 0 && r != height.size() - 1)){
            if (dict.find(max_v) != dict.end()){
                if (dict[max_v].size() == 2){
                    if (l < 0 && r < 0){
                        l = dict[max_v][0];
                        r = dict[max_v][1];
                    }
                    else{
                        if (pre_l < 0){
                            if (dict[max_v][0] > pre_r){
                                l = pre_r;
                                r = dict[max_v][1];
                            } else if (dict[max_v][0] < pre_l && dict[max_v][1] > pre_r){
                                l = dict[max_v][0];
                                r = dict[max_v][1];
                            } else if (dict[max_v][1] < pre_r){
                                l = dict[max_v][0];
                                r = pre_r;
                            }
                        }else{
                            if (dict[max_v][0] > pre_r){
                                l = pre_l;
                                r = dict[max_v][1];
                            } else if (dict[max_v][0] < pre_l && dict[max_v][1] > pre_r){
                                l = dict[max_v][0];
                                r = dict[max_v][1];
                            } else if (dict[max_v][1] < pre_l){
                                l = dict[max_v][0];
                                r = pre_r;
                            }else if (dict[max_v][0] > pre_l && dict[max_v][1] < pre_r){
                                l = pre_l;
                                r = pre_r;
                            }
                        }
                    }
                }
                else{
                    if (l < 0 && l < 0)
                        r = dict[max_v][0];
                    else{
                        if (pre_l < 0){
                            if (dict[max_v][0] > pre_r){
                                l = pre_r;
                                r = dict[max_v][0];
                            }else{
                                l = dict[max_v][0];
                                r = pre_r;
                            }
                        }else{
                            if (dict[max_v][0] < pre_l)
                                l = dict[max_v][0];
                            else if (dict[max_v][0] > pre_r)
                                r = dict[max_v][0];
                        }
                    }
                }
                if (l < 0){
                    pre_l = l;
                    pre_r = r;
                    max_v--;
                    continue;
                }
                if (pre_l < 0){
                    if (l == pre_l){
                        if (r > pre_r){
                            res += (r - pre_r) * max_v + max_v + 1;
                            cout << res << endl;
                            cout << 1 << endl;
                            pre_l = pre_r;
                            pre_r = r;
                            max_v--;
                            continue;
                        } else{
                            res += (pre_r - r) * max_v + max_v + 1;
                            cout << res << endl;
                            cout << 2 << endl;
                            pre_l = r;
                            max_v--;
                            continue;
                        }
                    }else{
                        if (l > pre_r){
                            res += (r - pre_r) * max_v + max_v + 1;
                            cout << res << endl;
                            cout << 3 << endl;
                            pre_l = pre_r;
                            pre_r = r;
                            max_v--;
                            continue;
                        }else if (r < pre_r){
                            res += (pre_r - l) * max_v + max_v + 1;
                            cout << res << endl;
                            cout << 4 << endl;
                            pre_l = l;
                            max_v--;
                            continue;
                        }else{
                            res += (r - l) * max_v + max_v + 1;
                            cout << res << endl;
                            cout << 5 << endl;
                            pre_l = l;
                            pre_r = r;
                            max_v--;
                            continue;   
                        }
                    }
                }
                if (l > pre_l && r < pre_r){
                    max_v--;
                    continue;
                }
                if (l == pre_l && r == pre_r){
                    max_v--;
                    continue;
                }
                if ((l == pre_l && r > pre_r) || l > pre_r){
                    res += (r - pre_r) * max_v;
                    pre_r = r;
                    max_v--;
                    continue;
                }
                if (l < pre_l && r > pre_r){
                    res += (pre_l - l) * max_v + (r - pre_r) * max_v;
                    pre_l = l;
                    pre_r = r;
                    max_v--;
                    continue;
                }
                if (r < pre_l){
                    res += (pre_l - l) * max_v;
                    pre_l = l;
                    max_v--;
                    continue;
                }
            }
        }
        return res;
    }
};

