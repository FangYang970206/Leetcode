class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 定义两个索引，代表nums要进行相互交换的值
        int ind_pre = nums.size(), ind_exchange = nums.size();
        // 先对vector进行反转，好处理
        reverse(begin(nums), end(nums));
        // 如果数组是排序好的，则直接返回
        if (! is_sorted(begin(nums), end(nums))){
            // 循环遍历，寻找最小的ind_exchange
            for (int i = 0; i < nums.size(); i++){
                //寻找ind_exchange
                auto targ = find_if(begin(nums) + i, end(nums), [&] (const int&cur) {return cur < nums[i];});
                //不等于end(nums), 判断是否小于之前的ind_exchange，小于进行替换
                if (targ != end(nums)){
                    if (ind_exchange > targ - begin(nums)) {
                        ind_exchange = targ - begin(nums);
                        ind_pre = i;
                    }
                }
                // 终止条件为当前索引大于ind_exchange，即找到ind_exchange，替换即可
                if (i >= ind_exchange){
                    swap(nums[ind_pre], nums[ind_exchange]);
                    // 替换后，对ind_exchange后面部分进行逆序排列，达到最小值
                    sort(begin(nums), begin(nums)+ind_exchange, [](int a, int b){return a > b;});
                    //最后反转，与初始反转相呼应
                    reverse(begin(nums), end(nums));
                    break;
                }
            }
        }
    } 
};