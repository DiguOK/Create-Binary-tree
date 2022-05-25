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
<br>转化代码如下：<br>
```
TreeNode* CreateTree(vector<string> list, int start) {
      //可以选择为任意标识符
    if (list[start] == "NULL") {
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(list[start]));
    //左右子节点计算
    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;
    if (lnode > list.size()) {
        root->left = NULL;
    }else {
        root->left = CreateTree(list, lnode);
    }

    if (rnode >= list.size()) {
        root->right = NULL;
    }else {
        root->right = CreateTree(list, rnode);
    }

    return root;
}
```
<br>将创建的TreeNode进行层序遍历展示：
<br>![image](https://user-images.githubusercontent.com/106227496/170207487-90941672-e453-456b-ab67-8e9a10d96e22.png)

# 2、数组表示完全二叉树——堆

# 3、通过寻找根节点来确定树的结构
[106.从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

[105.从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

[654.最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

题外话：二叉搜索树常用技巧： 中序遍历 结合 cur和pre
```
//98.验证二叉搜索树
class Solution {
public:
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
```
