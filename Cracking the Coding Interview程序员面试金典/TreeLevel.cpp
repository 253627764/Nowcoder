/*****************************************************
* \file TreeLevel.cpp
* \date 2016/05/31 17:05

* \����������
����һ�ö������������һ���㷨����������ĳһ��������н�������
�����������ĸ����ָ��TreeNode* root���Լ������Ͻ�����ȣ��뷵��һ������ListNode���������������н���ֵ���밴���ϴ������ҵ�˳�����ӣ�
��֤��Ȳ��������ĸ߶ȣ����Ͻ���ֵΪ�Ǹ������Ҳ�����100000��


* \���������
<����1>����α���
�����Ŀ����˼���������������ĳһ�������Ԫ�أ���������뵽���ǲ�α�������α�����򵥵ķ��������ö���ʵ�֣����Ǵ�ͳ�Ĳ�α��������ǿ����������Ԫ�أ���ô���������������֮���Ԫ���أ�
��ʵ���ǿ�����������������line1��line2����¼���������Ԫ�ظ���������line1�����ջ��һ�����µ�Ԫ�ظ�����line2������һ���ջԪ�صĸ�����
ÿ��line1Ϊ0��ʱ��˵����һ���Ѿ�ȫ����ջ����һ���Ѿ�ȫ����ջ����ô��α��������ͼ�һ�����ʱ��line2��ֵ���Ƹ�line1��line2=0��
����������dep���ʱ�򣬱����һ�������Ԫ�������ֹͣ������

//���о�������������ʵ�֣�һ����ŵ�ǰ��Ľ�㣬һ������һ��Ľ�㣻����һ������һ��vector��ŵ�ǰ�е����нڵ㣬ÿһ�����vector
*****************************************************/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
}; 

using namespace std;
#include <queue>
class TreeLevel{
public:
	ListNode* getTreeLevel(TreeNode* root,int dep){
	if (root==nullptr||dep<=0)
	{
		return nullptr;
	}
	ListNode* pHead = new ListNode(-1);
	ListNode* pNode = pHead;
	queue<TreeNode*> qu;
	qu.push(root);
	int lineCur = 1, lineNext = 0, num = 1;
	while (!qu.empty())
	{
		if (num==dep)
		{
			for (int i = 0; i < lineCur;i++)
			{
				TreeNode* node = qu.front();
				pNode->next = new ListNode(node->val);
				pNode = pNode->next;
				qu.pop();
			}
			return pHead->next;
		}
		TreeNode* node = qu.front();
		if (node->left)
		{
			qu.push(node->left);
			lineNext++;
		}
		if (node->right)
		{
			qu.push(node->right);
			lineNext++;
		}
		qu.pop();
		if (--lineCur==0)
		{
			lineCur = lineNext;
			lineNext = 0;
			num++;
		}
	}
	return pHead->next;
	}
};