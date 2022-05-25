#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* CreateTree(vector<string> list, int start) {

    if (list[start] == "NULL") {
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(list[start]));
    //左右子节点计算
    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;
    if (lnode >= list.size()) {
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

//层序遍历
void levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        cout << endl;
        result.push_back(vec);
    }
}

int main() {
    vector<string> vec = { "1", "3", "2", "NULL", "2" };
    TreeNode* root = CreateTree(vec, 0);
    levelOrderBottom(root);
    return 0;
}