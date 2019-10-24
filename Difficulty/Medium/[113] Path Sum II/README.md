# 问题描述

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

```bash
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
```

返回:

```bash
[
   [5,4,11,2],
   [5,8,4,5]
]
``` 

# 方法

有两种方法，一种是使用回溯法进行递归，很好理解，具体看代码。还有通过栈进行迭代求解，通过后序遍历进行求解，我开始也想这种方法，不过不知道怎么处理重复问题，在discuss中发现了通过prev指针记录之前节点，如果遇到当前节点的右孩子是它，则直接pop。

代码如下：
```java
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) return list;
        List<Integer> path = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        // sum along the current path
        int pathSum = 0;
        TreeNode prev = null;
        TreeNode curr = root;
        while (curr != null || !s.isEmpty()){
            // go down all the way to the left leaf node
            // add all the left nodes to the stack 
            while (curr != null){
                s.push(curr);
                // record the current path
                path.add(curr.val);
                // record the current sum along the current path
                pathSum += curr.val;
                curr = curr.left;
            }
            // check left leaf node's right subtree 
            // or check if it is not from the right subtree
            // why peek here? 
            // because if it has right subtree, we don't need to push it back
            curr = s.peek();
            if (curr.right != null && curr.right != prev){
                curr = curr.right;
                continue; // back to the outer while loop
            }
            // check leaf 
            if (curr.left == null && curr.right == null && pathSum == sum){
                list.add(new ArrayList<Integer>(path));
                // why do we need new arraylist here?
                // if we are using the same path variable path
                // path will be cleared after the traversal
            }
            // pop out the current value
            s.pop();
            prev = curr;
            // subtract current node's val from path sum 
            pathSum -= curr.val;
            // as this current node is done, remove it from the current path
            path.remove(path.size()-1);
            // reset current node to null, so check the next item from the stack 
            curr = null;
        }
        return list;
    }
```