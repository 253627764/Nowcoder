- ƽʱ��ϰһ��leetcode

- �ȸ���ţ����������ϰ��ͬ��[leetcode����](https://leetcode.com/)

## ��Ŀ

- Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## ˼·

- ����Ҫע����С����������ȵ�����:����������,����Ҫ���ǵ�ǰ�����Ƿ�Ϊ����������һ�������Ϊ0�����������������һֱ�����������������ֵ��������С��ȣ���Ҫ���ǵ�ǰ�����Ƿ�Ϊ�����������������˫����������С���Ϊ������������Сֵ�����ڵ�����������С���Ϊ������ȵ����ֵ����Ϊһ�������Ϊ0��.

## Nowcoder 

```C++
class Solution {
public:
    int run(TreeNode *root) {  //Ҷ�ӽ��ż�¼��ȣ�Ȼ�󲻶ϸ���
        if(root==nullptr)
            return 0;
        int l_depth=0,r_depth=0;
       
        l_depth=run(root->left);
        r_depth=run(root->right);
        
        if(l_depth==0)
            return r_depth+1;
        if(r_depth==0)
            return l_depth+1;
        if(l_depth<r_depth)
            return l_depth+1;
        else 
            return r_depth+1;
    }
};
```
## leetcode

```C++
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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};

```