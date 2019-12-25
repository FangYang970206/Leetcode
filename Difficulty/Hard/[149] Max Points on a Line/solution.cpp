/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> counter;
            int dup = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
                    dup++;
                else {
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int g = gcd(dx, dy);
                    counter[to_string(dx / g) + '_' + to_string(dy / g)]++;
                }
            }
            ans = max(ans, dup);
            for (auto p : counter)
                ans = max(ans, p.second + dup);
        }
        return ans;
    }
private:
    int gcd(int a, int b){
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};


// I don't know why it don't pass
class Solution {
public:
    struct pairhash{
        template<class T1, class T2>
            size_t operator()(const pair<T1, T2> &x) const{
            hash<T1> h1;
            hash<T2> h2;
            return h1(x.first) ^ h2(x.second);
        }
    };

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();
        unordered_map<pair<int, int>, int, pairhash> um;
        for (auto& p : points) {
            um[{p[0], p[1]}]++;
        }
        vector<vector<int>> new_points;
        for (auto& p : um)
            new_points.push_back({p.first.first, p.first.second});
        if (new_points.size() == 1)
            return um[{new_points[0][0], new_points[0][1]}];
        int maxPoints = 0, slope, bias;
        for (int i = 0; i < new_points.size(); i++) {
            unordered_map<pair<int, int>, int, pairhash> um_tmp;
            for (int j = i + 1; j < new_points.size(); j++) {
                if ((new_points[j][0] - new_points[i][0]) == 0) {
                    slope = INT_MAX;
                    bias = new_points[i][0];
                }else if (new_points[j][1] - new_points[i][1] == 0) {
                    slope = 0;
                    bias = new_points[j][1];
                }else{
                    slope = (new_points[j][1] - new_points[i][1]) / (new_points[j][0] - new_points[i][0]);
                    bias = slope * new_points[j][0] - new_points[j][1];
                }
                if (um_tmp.find({slope, bias}) == um_tmp.end())
                    um_tmp[{slope, bias}] += um[{new_points[i][0], new_points[i][1]}];
                um_tmp[{slope, bias}] += um[{new_points[j][0], new_points[j][1]}];
                
            }
            for (auto& p : um_tmp) 
                maxPoints = maxPoints < p.second ? p.second : maxPoints;
        }
        return maxPoints;
    }
};
// @lc code=end

