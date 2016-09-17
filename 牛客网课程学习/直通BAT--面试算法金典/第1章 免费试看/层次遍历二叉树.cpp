
//��һ�ö������������һ���㷨�����ղ�δ�ӡ��ö�������
//�����������ĸ����root���뷵�ش�ӡ������������ÿһ��һ��������д��棬���������˳���ղ����������£���ÿһ���������Ԫ�ذ��մ����������С���֤�����С�ڵ���500��

#include <iostream>
using namespace std;
#include <vector>
#include<deque>
#define N 10

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
		vector<vector<int> > vc;
		for (int level = 0;; level++)
		{
			if (!printTreeLevel(root, level))  //����رܿ��˷��ʶ����������
			{
				break;
			}
			vc.push_back(res);
			res.clear();
		}
		return vc;
	}

	int  printTreeLevel(TreeNode* root, int level)//������rootΪ���ڵ�ĵ�level���㡣ʧ�ܷ���0���ɹ�����1��
	{
		if (!root)  //ֻ��5�������к���û���ÿ�
		{
			return 0;
		}
		if (level == 0)
		{
			res.push_back(root->val);
			return 1;
		}
		return printTreeLevel(root->left, level - 1) + printTreeLevel(root->right, level - 1);
	}

	//�����������
	int deepth(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return deepth(root->left) > deepth(root->right) ? (deepth(root->left) + 1) : (deepth(root->right) + 1);
	}
private:
	vector<int> res;

	//������:�Ӹ��ڵ���������ν�ÿ���������ѹ��һ�����飬����cur��¼��ǰ���ʵĽ�㣬last��ǵ�ǰ������һ��������һ��λ�ã��±��0��ʼ������cur==last��ʾ��ǰ����ʽ���
public:
	//vector<vector<int> > printTree2(TreeNode* root)
	//{
	//	vector<vector<int> > res;
	//	if (!root)
	//	{
	//		return res;
	//	}
	//	vector<TreeNode*> vc;
	//	vc.push_back(root);
	//	vector<int> level;
	//	int cur = 0;
	//	int last = 1;
	//	while (cur < vc.size())
	//	{
	//		last = vc.size();
	//		while (cur < last)
	//		{
	//			level.push_back(vc[cur]->val);
	//			if (vc[cur]->left)
	//			{
	//				vc.push_back(vc[cur]->left);
	//			}
	//			if (vc[cur]->right)
	//			{
	//				vc.push_back(vc[cur]->right);
	//			}
	//			cur++;
	//		}
	//		res.push_back(level);
	//		level.clear();
	//	}
	//	return res;
	//}

	////���ö���
	//vector<vector<int> > printTree1(TreeNode* root) {
	//	vector<vector<int> > result;
	//	if (root == NULL) 
	//		return result;
	//	deque<TreeNode*> q;
	//	TreeNode* last = root;
	//	TreeNode* nlast = root;  //ָ����һ������һ�����
	//	vector<int> tmp;
	//	q.push_back(root);
	//	while (!q.empty()){
	//		TreeNode* cur = q.front();
	//		q.pop_front();
	//		tmp.push_back(cur->val);
	//		if (cur->left) {
	//			q.push_back(cur->left);
	//			nlast = cur->left;
	//		}
	//		if (cur->right) {
	//			q.push_back(cur->right);
	//			nlast = cur->right;
	//		}
	//		if (last == cur) {
	//			result.push_back(tmp);
	//			tmp.clear();
	//			last = nlast;
	//		}
	//	}
	//	return result;
	//}
	//private:
	//	char test[] ;
	//void createBiTree(TreeNode* root)  //�ַ������͵�����������
	//{
	//	int i = 0;
	//	char c;
	//	if (test[i]&&'#'==(c==test[i]))
	//	{
	//		root = nullptr;
	//	}
	//	else
	//	{
	//		root = new TreeNode(1);
	//		root->val = c;
	//		createBiTree(root->left);
	//		createBiTree(root->right);
	//	}
	//}

	//�������͵��������ķ���   //����������ʽ��������Ҫ�Ľ�
	//����һ�����
	TreeNode* createNode(int i)
	{
		TreeNode* q = new TreeNode(i);
		q->left = nullptr;
		q->right = nullptr;
		return q;
	}
	TreeNode* creteTree()
	{
		TreeNode* p[N]={nullptr };
		for (int i = 0; i < N;i++)
		{
			p[i] = createNode(i+1);
		}
		for (int i = 0; i < N / 2;i++)
		{
			p[i]->left = p[i * 2 + 1];
			p[i]->right = p[i * 2 + 2];
		}
		p[4]->right = nullptr;
		return p[0];
	}

public:
	int getLeafNode(TreeNode* T)
	{
		if (NULL == T)
			return 0;

		if (NULL == T->left && NULL == T->right)
			return 1;

		return getLeafNode(T->left) + getLeafNode(T->right);
	}
};

int main()
{
	TreePrinter t;
	TreeNode* T;
	T=t.creteTree();
	vector<vector<int> > vc = t.printTree(T);
	for (int i = 0; i < vc.size();i++)
	{
		for (int j = 0; j < vc[i].size();j++)
		{
			cout << vc[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}