# Create-Binary-tree
将数组表示的各种二叉树，转化为真正二叉树的形式，方便用于在自己IDE中转换使用

<br>二叉树的基本定义:
```
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
```

# 1、用nullptr或NULL进行标识的数组构建二叉树，如leetcode底层实现<br>
输入要求：数组是按照层序输入的，当该结点为空时，用特殊标识符号(nullptr\NULL\#)代替空的位置<br>
例如：[1,3,2,null,2]转化为<br>
![image](https://user-images.githubusercontent.com/106227496/170202443-9a05b8c9-635b-4045-9013-3f33a2a7a1ca.png)

