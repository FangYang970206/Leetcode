# 二叉树遍历

## 先序遍历

对于任何一个子树，必先访问父节点，然后访问左孩子，最后访问右孩子。

### 递归版

```c++
vector<int> preorderTraversalRecursive(TreeNode* root) {
    vector<int> nodes;
    preorderTraversalRecursiveHelper(nodes, root);
    return nodes;
}

void preorderTraversalRecursiveHelper(vector<int>& nodes, TreeNode* cur_node) {
    if (!cur_node) return;
    nodes.push_back(cur_node->val);
    preorderTraversalRecursiveHelper(nodes, cur_node->left);
    preorderTraversalRecursiveHelper(nodes, cur_node->right);
}
```

### 迭代版

```c++
vector<int> preorderTraversalIterative(TreeNode* root) {
    if (! root) return vector<int>();
    vector<int> nodes;
    stack<TreeNode*> todo;
    todo.push(root);
    while (!todo.empty()) {
        TreeNode* visit = todo.top();
        nodes.push_back(visit->val);
        todo.pop();
        if (visit->right) todo.push(visit->right);
        if (visit->left) todo.push(visit->left);
    }
    return nodes;
}
```

## 中序遍历

对于任何一个子树，必先访问左孩子节点，然后访问父节点，最后访问右孩子。

### 递归版

```c++
vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> nodes;
    inorderTraversalRecursiveHelper(nodes, root);
    return nodes;
}

void inorderTraversalRecursiveHelper(vector<int>& nodes, TreeNode* cur_node) {
    if (!cur_node) return;
    inorderTraversalRecursiveHelper(nodes, cur_node->left);
    nodes.push_back(cur_node->val);
    inorderTraversalRecursiveHelper(nodes, cur_node->right);
}
```

### 迭代版

```c++
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> todo;
    while(root || !todo.empty()){
        while (root) {
            todo.push(root);
            root = root->left;
        }
        root = todo.top();
        nodes.push_back(root->val);
        root = root->right;
        todo.pop();
    }
    return nodes;
}
```

## 后序遍历

对于任何一个子树，必先访问左孩子节点，然后访问右孩子，最后访问父节点。

### 递归版

```c++
vector<int> postorderTraversalRecursive(TreeNode* root) {
    vector<int> nodes;
    postorderTraversalRecursiveHelper(nodes, root);
    return nodes;
}

void postorderTraversalRecursiveHelper(vector<int>& nodes, TreeNode* cur_node) {
    if (!cur_node) return;
    postorderTraversalRecursiveHelper(nodes, cur_node->left);
    postorderTraversalRecursiveHelper(nodes, cur_node->right);
    nodes.push_back(cur_node->val);
}
```

### 迭代版

```c++
vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return vector<int>();
    vector<int> nodes;
    stack<TreeNode*> todo;
    TreeNode* last = nullptr;
    while (root || !todo.empty()) {
        if (root) {
            todo.push(root);
            root = root -> left;
        } else {
            TreeNode* node = todo.top();
            if (node -> right && node -> right != last) {
                root = node -> right;
            } else {
                nodes.push_back(node->val);
                last = node;
                todo.pop();
            }
        }
    }
    return nodes;
}
```

## 层级遍历

与前序，中序，后序遍历不同，层级遍历使用队列而不是栈。

```c++
vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return vector<vector<int>>();
    vector<vector<int>> levels;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        while(size--) {
            TreeNode* ptr = q.front();
            if (ptr->left) q.push(ptr->left);
            if (ptr->right) q.push(ptr->right);
            level.push_back(ptr->val);
            q.pop();
            if (size == 0)
                levels.push_back(level);
        }
    }
    return levels;
}
```