//��Ŀ����
//
//��ʵ��һ�����������һ�ö������Ƿ�Ϊ�����������
//�������ĸ����ָ��TreeNode* root���뷵��һ��bool����������Ƿ�Ϊ�����������


#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


class Checker {
public:
	//���뵽���Ƿ���true������� //��Ϊreturn true�д���
	bool checkBST(TreeNode* root) {  
		// write code here
		if (root == NULL) return true;
		if (root->left && root->left->val > root->val)
			return false;
		if (root->left && root->left->right && root->left->right->val>root->val)
			return false;
		if (root->right && root->right->val < root->val)
			return false;
		if (root->right&&root->right->left&&root->right->left->val < root->val)
			return false;

		return checkBST(root->left) && checkBST(root->right);
	}
};

//
//������Ա���Խ�䡷 ������⣺http ://blog.csdn.net/zdplife/article/category/5799903
//��Ŀ������
//<����1>
//���������뵽���Ƕ��������������Ľ��������ģ����������������ǿ���������������������ѱ�����������һ���������棬Ȼ���ж���������С�Ƿ����������飬������������飬���Ƕ��������������Ͳ��ǡ�
//���������ʱ�临�Ӷ���O(N)�����ǿռ临�ӶȱȽϸߣ���Ҫ�˷�O��N���Ĵ洢�ռ䡣
//<����2>
//��ʵ��<����1>�Ļ����ϣ����ǿ��������������ͬʱ���Ƚϴ�С��ÿ�μ�¼���ϴα�������Ԫ�ص�ֵ�������ǰԪ�ص�ֵ�����ϴα���Ԫ�ص�ֵ������ű��������򷵻�false����Ϊ�����¼��һ��ַ���ݣ�������Ҫ�õ������βν��д��ݡ�
//���������ʱ�临�Ӷ���<����1>��ʱ�临�Ӷ���ͬ��ֻ�ǿռ临�Ӷ�ֻ��Ҫһ��Ԫ��O(1)��
class Checker {
public:
	bool checkBST(TreeNode* root) {
		// write code here
		int min = INT_MIN;
		return inOrderCompare(root, min);
	}
	bool inOrderCompare(TreeNode* root, int &last)
	{
		if (root == NULL)
			return true;
		if (!inOrderCompare(root->left, last))
			return false;
		if (root->val < last)
			return false;
		last = root->val;
		if (!inOrderCompare(root->right, last))
			return false;
		return true;
	}
};
//<����3>
//���Ը��ݶ���������Ķ������жϣ��������Ķ��壬�����������Ľڵ�С�ڸ��ڵ㣬�����������Ľڵ���ڸ��ڵ㣬������������Ҳ�Ƕ���������������ڵݹ�Ĺ����У�����ֻ��Ҫ����������������ǰ���ڵ��Ӧ�Ķ����������нڵ�����ֵ����Сֵ����
//ͬʱ���ϵĸ��������������������ǰ�ڵ��ֵ��������������Χ�У���ֱ�ӷ���false��������ŵݹ��ɡ�




//�ǵݹ������������Ȼ���жϽ���Ƿ����
#include <stack>
#include <vector>
class Checker {
public:
	bool checkBST(TreeNode* root) {
		// write code here
		stack<TreeNode*> s;
		TreeNode *pNode = root;
		vector<int> data;
		while (pNode != NULL || !s.empty())
		{
			while (pNode != NULL)
			{
				s.push(pNode);
				pNode = pNode->left;
			}
			if (!s.empty())
			{
				pNode = s.top();
				data.push_back(pNode->val);
				s.pop();
				pNode = pNode->right;
			}
		}
		for (size_t i = 0; i < data.size() - 1; i++)
		{
			if (data[i] > data[i + 1])
				return false;
		}
		return true;
	}
};

//���������������������α���������������Ƿ�����������������
class Checker {
public:
	vector<int> res;
	bool checkBST(TreeNode* root) {
		// write code here
		if (root == NULL) return true;
		bool flag = false;
		inorder(root);
		for (int i = 0; i<res.size() - 1; i++)
		{
			if (res[i]>res[i + 1])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			return false;
		else
			return true;
	}
	void inorder(TreeNode* root){
		if (root == NULL) return;
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
	}
};