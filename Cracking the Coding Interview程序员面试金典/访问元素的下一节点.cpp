/*****************************************************
* \file Successor.cpp
* \date 2016/06/23 15:34

* \����������
��Ŀ����

�����һ���㷨��Ѱ�Ҷ�������ָ��������һ����㣨����������ĺ�̣���
�������ĸ����ָ��TreeNode* root�ͽ���ֵint p���뷵��ֵΪp�Ľ��ĺ�̽���ֵ��
��֤����ֵ���ڵ�����С�ڵ���100000��û���ظ�ֵ���������ں�̷���-1��

* \���������



*****************************************************/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

#include <iostream>
using namespace std;
#include <vector>
class Successor {
private:
	vector<int> vc;
public:
	void inOrder(TreeNode* root)
	{
		if (root != nullptr)
		{
			{
				inOrder(root->left);
				vc.push_back(root->val);
				inOrder(root->right);
			}
		}
	}
	int findSucc(TreeNode* root, int p) {
		// write code here
		inOrder(root);
		int val=-1;
		//������ͨ��AC??
		/*for (auto it = vc.begin(); it != vc.end();it++)
		{
			if (*it==p)
			{
				val= *(it++);
				break;
			}  
		}*/
		for (int i = 0; i < vc.size();i++)
		{
			if (vc[i]==p&&i<vc.size()-1)
			{
				return vc[i + 1];
			}
		}
		return val;
	}	
};