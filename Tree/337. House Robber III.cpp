#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach 1 
class Solution {
public:
    
    unordered_map<TreeNode*, vector<int>> dp;
    
    int solve(TreeNode* root, bool flag = false) {
        if(!root) return 0;
        
        if(dp.count(root) && dp[root][flag] != -1) return dp[root][flag];
        
        dp[root] = {-1, -1};
        
        if(flag) {
            return dp[root][flag] = solve(root->left, false) + solve(root->right, false);
        }
        
        // include 
        int incl = root->val + solve(root->left, true) + solve(root->right, true);
        
        // exclude
        int excl = solve(root->left, false) + solve(root->right, false);
        
        return dp[root][flag] = max(incl, excl);
    }
    
    int rob(TreeNode* root) {
        return solve(root);  
    }
};

// Approach 2 

class Solution {
public:
    
    pair<int, int> solve(TreeNode* root) {
        if(!root) return {0, 0};
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        return {
            max(left.first, left.second) + max(right.first, right.second), 
            root->val + left.first + right.first
        };
    }
    
    int rob(TreeNode* root) {
        auto amount = solve(root);
        return max(amount.first, amount.second);  
    }
};