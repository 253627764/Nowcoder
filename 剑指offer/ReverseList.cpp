//��Ŀ����
//
//����һ��������ת�����������������Ԫ�ء�

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

//˼·
//�ڷ�ת�����ʱ�����Ǻ������뵽�õ�ǰ����nextָ��ǰһ����㣬
//������������֮������ڵ�ԭ��next��ָ�Ľ����Ҳ����ˣ�����ÿ�����Ƕ�Ҫ�����µ�ǰһ��㣬
//��ǰ������һ�������ָ�룬ֻҪ��һ���Ϊ�գ���ô���Ǿ͵���ԭ������β������ʱ�����������ͷ��
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {

		ListNode *current = pHead;
		ListNode *pre = nullptr;
		ListNode *pNewNode = nullptr;
		if (pHead == nullptr)
		{
			return nullptr;
		}
		while (current != nullptr)  //��ǰ��㲻Ϊ��
		{
			ListNode *pnext = current->next; //��ǰ���ĺ��
			if (pnext == nullptr)
			{
				pNewNode = current;  //����㣬����ת�����ͷ�ڵ�
			}
			current->next = pre; //��ǰ���ĺ��תΪǰ��
			pre = current;  //ǰ��תΪ��ǰ���
			current = pnext;  //��ǰ��������
		}
		return pNewNode;
	}
};

//1������ָ����������ͬʱ�������Ƚ������뵽���Ǳ����Ը���
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		if (pHead->next == nullptr) return pHead;

		ListNode *pBefore = pHead, *p = pHead->next, *pAfter = p->next;
		while (pAfter) {
			p->next = pBefore; // reverse
			pBefore = p;
			p = pAfter;
			pAfter = pAfter->next;
		}
		p->next = pBefore; //������һ������ǰ��
		pHead->next = nullptr; //β�����Ϊ��
		return p;
	}
};

//2����ԭ�����ͷ��һ��һ��ȡ�ڵ㲢���뵽�������ͷ��
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		ListNode* head = pHead;
		pHead = pHead->next;
		head->next = nullptr; //��ʱ��headΪβ���
		while (pHead) {
			ListNode *next = pHead->next;
			pHead->next = head;
			head = pHead; //
			pHead = next;
		}
		return head;
	}
};

//ʹ��һ��ջ��������⣬C++

#include<stack>
using namespace std;
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		ListNode * p = pHead;
		ListNode * newHead;
		stack<ListNode *> stack1;
		while (p->next != NULL)
		{
			stack1.push(p);
			p = p->next;
		}
		newHead = p;
		while (!stack1.empty())
		{
			p->next = stack1.top();
			p = p->next;
			stack1.pop();
		}
		p->next = NULL;
		return newHead;
	}
};


//��Ŀ����
//
//����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
//�������� :
//����Ϊ����ı�ͷ
//
//
//������� :
//���Ϊ��Ҫ��ӡ�ġ��������ı�ͷ
#include<vector>
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {

		//std::stack<ListNode*> nodes;

		// ListNode *pNode = head;
		// while(pNode != NULL)
		// {
		//      nodes.push(head);
		//      head = head->next;
		// }

		//  while(!nodes.empty())
		//  {
		//     head = nodes.top();
		//     printf("%d\t" ,head->val);
		//     nodes.pop();
		//  }

		vector<int> dev1;
		if (head != NULL)
		{
			if (head->next != NULL)
			{
				dev1 = printListFromTailToHead(head->next);
			}
			dev1.push_back(head->val);
		}
		return dev1;

	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		//����ջ�������������       
		stack<int> stack;
		vector<int> vector;
		struct ListNode *p = head;
		if (head != NULL) {
			stack.push(p->val);
			while ((p = p->next) != NULL) {
				stack.push(p->val);
			}
			while (!stack.empty()) {
				vector.push_back(stack.top());
				stack.pop();
			}
		}
		return vector;
	}

};

/***
*��ԭ������˵������ջ��ʹ������Ľ��˼·�ǳ������ˡ�
*ע�⺯���ķ���������int���͵�vector
*/
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head)
	{
		vector<int> vec;         //����һ��vector���Node��int���͵�valֵ
		std::stack<ListNode *>nodes;
		ListNode *pNode = head;
		//������ջ
		while (pNode != NULL)
		{
			nodes.push(pNode);    //�������нڵ㣬�����ѹ��ջ��
			pNode = pNode->next;
		}
		//������ջ
		while (!nodes.empty())
		{
			pNode = nodes.top();        //����Ľ��ָ��ʼ��ָ��ջ����ȡ��ջ������valֵ���뵽�����vec�У�Ȼ�󵯳�ջ��Ԫ�ء���ջ����ջ�ױ���
			vec.push_back(pNode->val);
			nodes.pop();
		}
		return vec;    //����ֵΪint�͵�vector
	}
};