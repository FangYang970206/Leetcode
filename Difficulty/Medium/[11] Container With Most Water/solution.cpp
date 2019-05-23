class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, h = 0, sub = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            h = min(height[i], height[j]);
            sub = j - i;
            maxArea = max(maxArea, sub*h);
            if (h == height[i]){
                while (i < j && h >= height[i+1]) i++;
                if (sub == j - i) i++;
            }
            else{
                while(i < j && h >= height[j-1]) j--;
                if(sub == j - i) j--;
            }
        }
        return maxArea;
    }
};