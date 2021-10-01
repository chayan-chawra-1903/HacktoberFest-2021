class Solution {
public:
    pair<TreeNode*,TreeNode*> convert(TreeNode* root)
    {
        pair<TreeNode*,TreeNode*> ans(nullptr,nullptr);
        if(root->left==nullptr && root->right==nullptr)
        {
            ans.first=root;
            ans.second=root;
        }
        else if(root->right==nullptr)
        {
            pair<TreeNode*,TreeNode*> leftPart=convert(root->left);
            root->right=leftPart.first;
            root->left=nullptr;
            ans.first=root;
            ans.second=leftPart.second;
        }
        else if(root->left==nullptr)
        {
            pair<TreeNode*,TreeNode*> rightPart=convert(root->right);
            root->right=rightPart.first;
            ans.first=root;
            ans.second=rightPart.second;
        }
        else
        {
            pair<TreeNode*,TreeNode*> leftPart=convert(root->left);
            pair<TreeNode*,TreeNode*> rightPart=convert(root->right);
            root->left=nullptr;
            root->right=leftPart.first;
            leftPart.second->right=rightPart.first;
            ans.first=root;
            ans.second=rightPart.second;
        }
        return ans;
    }
    
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return ;
        convert(root);
    }
};