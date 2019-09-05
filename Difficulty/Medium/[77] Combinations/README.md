# 问题描述

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

# 例子

```bash
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

# 方法

我的方法84ms使用的是回溯，构建搜索树，遍历可能的每一个集合，但在循环体内部设立了一个条件判断，去除不可能的集合，耗时较长。下面的24ms使用的是num计数，可以很好地避免训练内部的条件判断。最厉害的还是最下面的8ms的，直接使用迭代的方式进行求解，观察到集合的变化规律，很是巧妙。

```c++
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        if(n<k)return res;
        vector<int> temp(0,k);
        combine(res,temp,0,0,n,k);
        return res;
    }
    
    void combine(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num==k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
            }
        }
};
```

```c++
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
```