# 问题描述

给定一个正整数 n，生成一个包含 1 到 n的平方 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

# 例子

```bash
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

# 方法

方法与leetcode 54类似，不过这次换成的是赋值, 而不是push back, 由于是方阵，所以也无需循环内部的条件判断，更简洁。 

```c++
vector<vector<int>> generateMatrix(int n) {
    if (n < 1) return vector<vector<int>> ();
    vector<vector<int>> res {n, vector<int>(n, 0)};
    int row_begin = 0, row_end = n;
    int col_begin = 0, col_end = n;
    int begin = 1, end = n * n;
    while (begin <= end){
        for (int col = col_begin; col < col_end; col++)
            res[row_begin][col] = begin++;
        for (int row = row_begin + 1; row < row_end ; row++)
            res[row][col_end - 1] = begin++;
        for (int col = col_end - 2; col >= col_begin; col--)
            res[row_end - 1][col] = begin++;
        for (int row = row_end - 2; row > row_begin; row--)
            res[row][col_begin] = begin++;
        row_begin++, col_begin++, row_end--, col_end--; 
    }
    return res;
}
```