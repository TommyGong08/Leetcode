/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void LDR(TreeNode* root,vector<int>& v){
        if(root == NULL ) {
            v.push_back(-1);
            return ;
        }
        if(root != NULL ){//root 非空
            if(root->left ==NULL && root->right == NULL){
                v.push_back(root->val);
            }
            else{
                LDR(root->left,v);
                v.push_back(root->val);
                LDR(root->right,v);
            }
            
        }
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> v;
        LDR(root,v);
        //判断vector是否对称
        if(v.size()%2 == 0) return false;
        if(v.size() >5 && root->left->val!=root->right->val) return false; 
        int i = 0;
        int j = v.size()-1;
        while(i!=j){
           if(v[i] == v[j]){
               i++; j--;
           }
           else return false;
        }
        if( i==j && i == (v.size()-1)/2) return true;
        else return false;
    }
};