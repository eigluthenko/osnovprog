#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumRecursive(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumRecursive(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        
        int leftSum = std::max(0, maxPathSumRecursive(node->left, maxSum));
        int rightSum = std::max(0, maxPathSumRecursive(node->right, maxSum));
        
        maxSum = std::max(maxSum, leftSum + rightSum + node->val);
        
        return std::max(leftSum, rightSum) + node->val;
    }
};

TreeNode* buildTree(const std::vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }
    
    TreeNode* node = new TreeNode(values[index]);
    node->left = buildTree(values, 2 * index + 1);
    node->right = buildTree(values, 2 * index + 2);
    
    return node;
}

int main() {
    std::cout << "Введите количество узлов в бинарном дереве: ";
    int n;
    std::cin >> n;

    std::vector<int> values(n);
    std::cout << "Введите значения узлов через пробел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    TreeNode* root = buildTree(values, 0);

    Solution solution;
    std::cout << "Максимальная сумма пути: " << solution.maxPathSum(root) << std::endl;

    delete root;

    return 0;
}