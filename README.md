# Create-Binary-tree
将数组表示的各种二叉树，转化为真正二叉树的形式，方便用于在自己IDE中转换使用
二叉树的定义:
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

1、用nullptr或NULL进行标识的数组构建二叉树，如leetcode底层实现
[1,3,2,null,2]->
![image](https://user-images.githubusercontent.com/106227496/170201747-537b9b96-fa2b-4684-bbb6-9436a8ba8b06.png)

