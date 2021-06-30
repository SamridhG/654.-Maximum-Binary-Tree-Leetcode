/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * make(vector<int>& nums,int start,int end)
    {
        if(start<=end)
        {
            int index=max_element(nums.begin()+start,nums.begin()+end+1)-nums.begin();
            TreeNode *rt;
            rt=new TreeNode(nums[index]);
            rt->left=make(nums,start,index-1);
            rt->right=make(nums,index+1,end);
            return rt;
            
        }
        return NULL;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        TreeNode *root;
        root=make(nums,start,end);
        return root;
    }
};
