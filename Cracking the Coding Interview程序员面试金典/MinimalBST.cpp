/*****************************************************
* \file MinimalBST.cpp
* \date 2016/05/30 16:00

* \����������
����һ��Ԫ�ظ�����ͬ�Ұ��������е��������У����дһ���㷨������һ�ø߶���С�Ķ����������
����һ����������int[] vals,�뷵�ش����Ķ���������ĸ߶ȡ�

* \���������
����û���ø������Ĺ�����̣����Կ���ֱ��ͨ�����ɵķ�ʽ����ó���������������������Ծ�ʹ�õݹ�ķ�ʽģ�����Ĺ����������յõ�������������
��Ŀ��Ҫ�����ĸ߶���Сʵ�������ù���һ��ƽ�������������˵Ϊ�����������������Ľڵ�����Խ�ӽ�Խ�á�

///��Ȼ����ֱ�ӹ�ʽ��߶ȣ�����Ҳд�˸�����˳����߶ȵ�
*****************************************************/
#include <iostream>
using namespace std;
#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
class MinimalBST {
public:
	TreeNode* buildBST(vector<int> _vals,int _left,int _right)
	{
		if (_left>_right)
		{
			return nullptr;
		}
		int mid = _left + (_right - _left) / 2;
		TreeNode* root = new TreeNode(_vals[mid]);
		root->left = buildBST(_vals, _left, mid - 1);
		root->right = buildBST(_vals, mid + 1, _right);
		return root;
    }
	int highBST(TreeNode* _root)
	{
		if (_root==nullptr)
		{
			return 0;
		}
		int left = highBST(_root->left);
		int right = highBST(_root->right);
		return left > right ? (left + 1) : (right + 1);
	}
	int buildMinimalBST(vector<int> vals) {
		// write code here
		if (vals.size()<=0)
		{
			return 0;
		}
		TreeNode* root = buildBST(vals,0,vals.size()-1);
		return highBST(root);
	}
};